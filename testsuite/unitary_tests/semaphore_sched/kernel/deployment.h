// This file has been automatically generated by gen_deployment.
// Do not make manual modifications there or they will be lost.

#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#include <core/schedvalues.h>

#define POK_CONFIG_NB_LOCKOBJECTS 2
#define POK_CONFIG_NB_PARTITIONS 3
#define POK_CONFIG_NB_THREADS 9
#define POK_CONFIG_PARTITIONS_NLOCKOBJECTS                                     \
  { 1, 1, 0 }
#define POK_CONFIG_PARTITIONS_NTHREADS                                         \
  { 3, 3, 1 }
#define POK_CONFIG_PARTITIONS_SCHEDULER                                        \
  { POK_SCHED_STATIC, POK_SCHED_STATIC, POK_SCHED_RR }
#define POK_CONFIG_PARTITIONS_SIZE                                             \
  { 133120, 133120, 133120 }
#define POK_CONFIG_PROGRAM_NAME                                                \
  { "pr1/pr1.elf", "pr2/pr2.elf", "pr3/pr3.elf" }
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 101000000
#define POK_CONFIG_SCHEDULING_NBSLOTS 3
#define POK_CONFIG_SCHEDULING_SLOTS                                            \
  { 50000000, 50000000, 1000000 }
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION                                 \
  { 0, 1, 2 }

#define POK_NEEDS_ASSERT 1
#define POK_NEEDS_CONSOLE 1
#define POK_NEEDS_DEBUG 1
#define POK_NEEDS_LOCKOBJECTS 1
#define POK_NEEDS_SCHED_STATIC 1
#define POK_NEEDS_SHUTDOWN 1
#define POK_NEEDS_THREAD_SLEEP 1
#define POK_NEEDS_TIME 1

typedef enum {
  pok_part_identifier_pr1 = 0,
  pok_part_identifier_pr2 = 1,
  pok_part_identifier_pr3 = 2
} pok_part_identifiers_t;

typedef enum {
  pok_part_id_pr1 = 0,
  pok_part_id_pr2 = 1,
  pok_part_id_pr3 = 2
} pok_part_id_t;

typedef enum { pok_nodes_node1 = 0 } pok_node_id_t;

#endif // __POK_KERNEL_GENERATED_DEPLOYMENT_H_
