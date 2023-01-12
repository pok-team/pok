/*
 *                               POK header
 *
 * The following file is a part of the POK project. Any modification should
 * be made according to the POK licence. You CANNOT use this file or a part
 * of a file for your own project.
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2022 POK team
 */

#include <core/partition.h>
#include <core/semaphore.h>
#include <core/thread.h>
#include <core/time.h>
#include <types.h>
#include <libc/stdio.h>
#include "main.h"

void task(){
  while(1){}
}

void create_task_3(){
  uint32_t tid;
  pok_thread_attr_t tattr;
  
  tattr.deadline = 300;
  tattr.time_capacity = 40;
  tattr.priority = 60;
  tattr.processor_affinity = 0;
  tattr.entry = task;

  pok_thread_create(&tid, &tattr);
  printf("Create Thread 3.\n");
}

int main() {
  pok_ret_t ret;
  pok_thread_attr_t tattr;
  uint32_t tid;

  tattr.period = 400;
  tattr.deadline = 80;
  tattr.priority = 100;
  tattr.time_capacity = 40;
  tattr.processor_affinity = 0;
  tattr.entry = task;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] pok_thread_create (1) return=%d\n", ret);

  tattr.period = 300;
  tattr.deadline = 200;
  tattr.priority = 80;
  tattr.time_capacity = 60;
  tattr.processor_affinity = 0;
  tattr.entry = task;
  tattr.isThread2 = TRUE;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] pok_thread_create (2) return=%d\n", ret);

  tattr.period = 800;
  tattr.deadline = 800;
  tattr.priority =
  tattr.time_capacity = 100;
  tattr.processor_affinity = 0;
  tattr.entry = task;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P1] pok_thread_create (2) return=%d\n", ret);
  pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite();

  return (0);
}
