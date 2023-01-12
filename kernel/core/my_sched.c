#include "../../mytests/part4/pr1/main.h"
#include <libc.h>
#include <core/my_sched.h>
#include <core/time.h>
#include <core/sched.h>
#include <core/thread.h>
#include <core/partition.h>
#include <types.h>

extern pok_thread_t pok_threads[];

uint32_t pok_my_sched_part_prio(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  uint32_t elected, from;
  uint32_t res = IDLE_THREAD;
  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  elected = from;
  do {
      if (pok_threads[elected].state == POK_STATE_RUNNABLE && 
      pok_threads[elected].priority>pok_threads[res].priority) {
            res = elected;
        }
        elected++;
        if (elected >= index_high) {
          elected = index_low;
        }
    } while (elected != from);
  if(pok_threads[res].isThread2){
    create_task_3();
  }
  #ifdef POK_NEEDS_DEBUG
    uint8_t current_proc = pok_get_proc_id();
    // printf("--- Processor %hhd, Time: %u \n",current_proc,(unsigned)(POK_GETTICK()));
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
  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  elected = from;
  do {
      if (pok_threads[elected].state == POK_STATE_RUNNABLE
      &&pok_threads[elected].ab_deadline<pok_threads[res].ab_deadline) {
            res = elected;
        }
        elected++;
        if (elected >= index_high) {
          elected = index_low;
        }
    } while (elected != from);
  if(pok_threads[res].isThread2){
    create_task_3();
  }
    #ifdef POK_NEEDS_DEBUG
    uint8_t current_proc = pok_get_proc_id();
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
  if(pok_threads[res].isThread2){
    create_task_3();
  }
     #ifdef POK_NEEDS_DEBUG
    uint8_t current_proc = pok_get_proc_id();
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

uint32_t pok_my_sched_part_mlfq(const uint32_t index_low, const uint32_t index_high,
                           const uint32_t prev_thread,
                           const uint32_t current_thread) {
  uint32_t elected, from;
  uint32_t res = IDLE_THREAD;
  from = current_thread == IDLE_THREAD? prev_thread:current_thread;
  elected = from;
  do {
      if(((unsigned)(POK_GETTICK())!=0) && ((unsigned)(POK_GETTICK())%RESET == 0))
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


  if(pok_threads[res].remaining_time_capacity == pok_threads[res].time_capacity)
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
  if(pok_threads[res].isThread2){
    create_task_3();
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

    // printf("--- Processor %hhd, Time: %u \n",current_proc,(unsigned)(POK_GETTICK()));
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