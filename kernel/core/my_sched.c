#include <libc.h>
#include <core/my_sched.h>
#include <core/time.h>
#include <core/sched.h>
#include <core/thread.h>
#include <core/partition.h>

extern pok_thread_t pok_threads[];
uint32_t round = 0;

uint32_t pok_my_sched_part_prio(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  uint32_t elected, from;
  // uint8_t current_proc = pok_get_proc_id();
  uint32_t res = IDLE_THREAD;
  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  elected = from;
  do {
      if (pok_threads[elected].state == POK_STATE_RUNNABLE && 
      pok_threads[elected].priority>pok_threads[res].priority) {
        #ifdef POK_ISAPP
            if(elected == 3 && pok_threads[elected].round >= round){
                elected ++;
                continue;
            }
        #endif
            res = elected;
        }
        elected++;
        if (elected >= index_high) {
          elected = index_low;
        }
    } while (elected != from);
  #ifdef POK_ISAPP
    if(res == 2 && pok_threads[res].remaining_time_capacity == 20){
      round++;
    }
    else if(res == 3 && pok_threads[res].remaining_time_capacity == 20){
      pok_threads[res].round++;
    }
  #endif
  #ifdef POK_NEEDS_DEBUG
    uint8_t current_proc = pok_get_proc_id();
    // printf("--- Processor %hhd, Time: %u \n",current_proc,(unsigned)(POK_GETTICK()));
    if(from != 0 && pok_threads[from].remaining_time_capacity == 0){
      printf("P%hhdT%d: Finished (priority: %d) at %u\n",
      current_proc,
      from,
      pok_threads[from].priority,
      (unsigned)(POK_GETTICK()));
    }
    if(res == IDLE_THREAD){
      printf("Idle at %u.\n",(unsigned)(POK_GETTICK()));
    }
    else if(pok_threads[res].remaining_time_capacity == pok_threads[res].time_capacity){
      printf("P%hhdT%d: Start scheduling (priority: %d) at %u\n",
      current_proc,
      res,
      pok_threads[res].priority,
      (unsigned)(POK_GETTICK()));
    }
    else{
      printf("P%hhdT%d: Remaining time:%u (priority: %d) at %u\n",
      current_proc,
      res,
      (unsigned)(pok_threads[res].remaining_time_capacity),
      pok_threads[res].priority,
      (unsigned)(POK_GETTICK()));
    }
  #endif
  return res;
}

uint32_t pok_my_sched_part_edf(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  uint32_t elected, from;
  // uint8_t current_proc = pok_get_proc_id();
  uint32_t res = IDLE_THREAD;
  int64_t minddl = 1000000;
  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  if(from == IDLE_THREAD){
    from = IDLE_THREAD + 1;
  }
  elected = from;
  do {
      if (pok_threads[elected].state == POK_STATE_RUNNABLE
      &&pok_threads[elected].ab_deadline < minddl) {
          #ifdef POK_ISAPP
            if(elected == 3 && pok_threads[elected].round >= round){
                elected ++;
                continue;
            }
          #endif
            res = elected;
            minddl = pok_threads[elected].ab_deadline;
        }
        elected++;
        if (elected >= index_high) {
          elected = index_low;
        }
    } while (elected != from);
  #ifdef POK_ISAPP
    if(res == 2 && pok_threads[res].remaining_time_capacity == 20){
      round++;
    }
    if(res == 3 && pok_threads[res].remaining_time_capacity == 20){
      pok_threads[res].round ++ ;
    }
  #endif
  #ifdef POK_NEEDS_DEBUG
    uint8_t current_proc = pok_get_proc_id();
    // printf("--- Processor %hhd, Time: %u \n",current_proc,(unsigned)(POK_GETTICK()));
    if(res == IDLE_THREAD){
      printf("Idle at %u.\n",(unsigned)(POK_GETTICK()));
    }
    else if(pok_threads[res].remaining_time_capacity == pok_threads[res].time_capacity){
      printf("P%hhdT%d: Start scheduling (deadline: %u) at %u\n",
      current_proc,
      res,
      (unsigned)(pok_threads[res].ab_deadline),
      (unsigned)(POK_GETTICK()));
    }
    else{
      printf("P%hhdT%d: Remaining time:%u (deadline: %u) at %u\n",
      current_proc,
      res,
      (unsigned)(pok_threads[res].remaining_time_capacity),
      (unsigned)(pok_threads[res].ab_deadline),
      (unsigned)(POK_GETTICK()));
    }
    if(pok_threads[res].remaining_time_capacity ==  20){
        printf("P%hhdT%d: Finished (deadline: %u) at %u\n",
        current_proc,
        res,
        (unsigned)(pok_threads[res].ab_deadline),
        (unsigned)(POK_GETTICK()+20));
    }
  #endif
  return res;
}

uint32_t my_rr(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread, const bool_t is_wrr) {
  
  
  uint32_t elected, from;
  // uint8_t current_proc = pok_get_proc_id();
  uint32_t res = IDLE_THREAD;

  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  elected = from;
  if (elected != IDLE_THREAD && 
  (pok_threads[elected].state == POK_STATE_RUNNABLE)&&
  pok_threads[elected].remaining_round > 0){
    res = elected;  
    pok_threads[elected].remaining_round--; 
  }
  else{
    do {
      elected++;
      if (elected >= index_high) {
        elected = index_low;
      }
      if(pok_threads[elected].state == POK_STATE_RUNNABLE){
        #ifdef POK_ISAPP
            if(elected == 3 && pok_threads[elected].round >= round){
                continue;
            }
        #endif
        res = elected;
        break;
      }
    } while (elected != from);
    if(res != IDLE_THREAD){
      if(is_wrr){
        pok_threads[res].remaining_round = POK_LAB_SCHED_ROUND*pok_threads[res].weight;
      }
      else{
        pok_threads[res].remaining_round = POK_LAB_SCHED_ROUND;
      }
      pok_threads[res].remaining_round --;
    }
  }
  #ifdef POK_ISAPP
    if(res == 2 && pok_threads[res].remaining_time_capacity == 20){
      round++;
    }
    else if(res == 3 && pok_threads[res].remaining_time_capacity == 20){
      pok_threads[res].round++;
    }
  #endif
     #ifdef POK_NEEDS_DEBUG
    uint8_t current_proc = pok_get_proc_id();
    if(from != 0 && pok_threads[from].remaining_time_capacity == 0){
      printf("P%hhdT%d: Finished (deadline: %u) at %u\n",
      current_proc,
      from,
      (unsigned)(pok_threads[from].ab_deadline),
      (unsigned)(POK_GETTICK()));
    }
    if(res == IDLE_THREAD){
      printf("Idle at %u.\n",(unsigned)(POK_GETTICK()));
    }
    else if(pok_threads[res].remaining_time_capacity == pok_threads[res].time_capacity){
      printf("P%hhdT%d: Start scheduling at %u\n",
      current_proc,
      res,
      (unsigned)(POK_GETTICK()));
    }
    else{
      printf("P%hhdT%d: Remaining time:%u at %u\n",
      current_proc,
      res,
      (unsigned)(pok_threads[res].remaining_time_capacity),
      (unsigned)(POK_GETTICK()));
    }
  #endif 
  return res;
}

uint32_t pok_my_sched_part_rr(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  return my_rr(index_low,index_high,prev_thread,current_thread,FALSE);
                           }
uint32_t pok_my_sched_part_wrr(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  return my_rr(index_low,index_high,prev_thread,current_thread,TRUE); 
                           }

uint32_t pok_my_sched_part_prio_edf(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  uint32_t elected, from;
  // uint8_t current_proc = pok_get_proc_id();
  uint32_t res = IDLE_THREAD;
  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  elected = from;
  do {
    int prioCmp = pok_threads[elected].priority - pok_threads[res].priority;
    int deadlineCmp = pok_threads[elected].ab_deadline - pok_threads[res].ab_deadline;
    if (pok_threads[elected].state == POK_STATE_RUNNABLE && 
    (prioCmp > 0 || (prioCmp == 0 && deadlineCmp < 0))) { // prio is higher or (same prio but ddl is closer)
        #ifdef POK_ISAPP
            if(elected == 3 && pok_threads[elected].round >= round){
                elected ++;
                continue;
            }
        #endif
          res = elected;
      }
      elected++;
      if (elected >= index_high) {
        elected = index_low;
      }
    } while (elected != from);
  #ifdef POK_ISAPP
    if(res == 2 && pok_threads[res].remaining_time_capacity == 20){
      round++;
    }
    else if(res== 3 && pok_threads[res].remaining_time_capacity == 20){
      pok_threads[res].round++;
    }
  #endif
  #ifdef POK_NEEDS_LIGHTER_REPORT
    uint32_t last_finished_thread = 0;
    if(from != last_finished_thread && pok_threads[from].remaining_time_capacity <= 0){
      uint64_t now = POK_GETTICK();
      printf("Thread %u finished at %u, deadline %s, next activation: %u\n",
              from,
              (unsigned)now,
              (uint64_t)pok_threads[from].ab_deadline >= now ? "met" : "missed",
              (uint64_t)pok_threads[from].next_activation == now ? 
                (unsigned)(now+pok_threads[from].period) : (unsigned)pok_threads[from].next_activation);
      last_finished_thread = from;
    }

    if(res == IDLE_THREAD){
      printf("Idle at %u.\n",(unsigned)(POK_GETTICK()));
    }
    else if(pok_threads[res].remaining_time_capacity == pok_threads[res].time_capacity){
      printf("Thread %d started scheduling at %u\n",
      res,
      (unsigned)(POK_GETTICK()));
    }

  #endif
  return res;
}
uint32_t pok_my_sched_part_mlfq(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  uint32_t elected, from;
  // uint8_t current_proc = pok_get_proc_id();
  uint32_t res = IDLE_THREAD;
  pok_threads[IDLE_THREAD].current_queue = QUEUE_NUMBER;
  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  elected = from;
  do {
      if((elected!=IDLE_THREAD) && ((unsigned)(POK_GETTICK())!=0) && ((unsigned)(POK_GETTICK())%RESET == 0))
      {
        pok_threads[elected].current_queue = 0;
        pok_threads[elected].current_queue_run_time = 0;
      }
      if (pok_threads[elected].state == POK_STATE_RUNNABLE && 
          pok_threads[elected].current_queue <= pok_threads[res].current_queue) {
            res = elected;
        }
        elected++;
        if (elected >= index_high) {
          elected = index_low;
        }
  } while (elected != from);


  if((res != IDLE_THREAD) && (pok_threads[res].remaining_time_capacity == pok_threads[res].time_capacity))
  {
    pok_threads[res].current_queue = 0;
    pok_threads[res].current_queue_run_time = 0;
  }

  int flag = 0;

  if(pok_threads[res].current_queue_run_time >= pok_threads[res].current_queue+1)
  {
    if(pok_threads[res].current_queue < QUEUE_NUMBER-1)
    {
      pok_threads[res].current_queue++;
      pok_threads[res].current_queue_run_time = 0;
      flag = 1;
    }
  }
  
  #ifdef POK_NEEDS_DEBUG
    uint8_t current_proc = pok_get_proc_id();


    if(flag && res != IDLE_THREAD){
      printf("P%hhdT%d: Decrease to queue:%u at %u\n",
      current_proc,
      res,
      (unsigned)(pok_threads[res].current_queue),
      (unsigned)(POK_GETTICK()));
    }

    if(((unsigned)(POK_GETTICK())!=0) && ((unsigned)(POK_GETTICK())%RESET == 0)){
        printf("RESET happen at %u.\n",(unsigned)(POK_GETTICK()));
    }
    if(res == IDLE_THREAD){
      printf("Idle at %u.\n",(unsigned)(POK_GETTICK()));
    }
    else if(pok_threads[res].remaining_time_capacity == pok_threads[res].time_capacity){
      printf("P%hhdT%d: Start scheduling (queue: %d) at %u\n",
      current_proc,
      res,
      pok_threads[res].current_queue,
      (unsigned)(POK_GETTICK()));
    }
    else{
      printf("P%hhdT%d: Remaining time:%u (queue: %d) at %u\n",
      current_proc,
      res,
      (unsigned)(pok_threads[res].remaining_time_capacity),
      pok_threads[res].current_queue,
      (unsigned)(POK_GETTICK()));
    }
  #endif

  pok_threads[res].current_queue_run_time ++;

  return res;
}