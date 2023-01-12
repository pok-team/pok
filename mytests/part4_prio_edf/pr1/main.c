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

#include <libc/stdio.h>
#include <libc/string.h>
#include <core/thread.h>
#include <core/partition.h>
#include <types.h>

static void task_ctrl();
static void task_monitor();
static void task_evaluate();
static void task_notify();

int main() {
    uint32_t tid;
    pok_thread_attr_t tattr;
    memset(&tattr, 0, sizeof(pok_thread_attr_t));

    tattr.priority = 30;
    tattr.period = 300;
    tattr.time_capacity = 120;
    tattr.deadline = 300;
    tattr.entry = task_ctrl;
    pok_thread_create(&tid, &tattr);

    tattr.priority = 20;
    tattr.period = 200;
    tattr.time_capacity = 20;
    tattr.deadline = 160;
    tattr.entry = task_monitor;
    pok_thread_create(&tid, &tattr);

    tattr.priority = 10;
    tattr.period = 200;
    tattr.time_capacity = 20;
    tattr.deadline = 200;
    tattr.entry = task_evaluate;
    pok_thread_create(&tid, &tattr);

    tattr.priority = 10;
    tattr.period = 200;
    tattr.time_capacity = 20;
    tattr.deadline = 200;
    tattr.entry = task_notify;
    pok_thread_create(&tid, &tattr);

    pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
    pok_thread_wait_infinite();
    return 0;
}

static void task_ctrl() {
    for (;;) {
    }
}

static void task_monitor() {
    for (;;) {
    }
}

static void task_evaluate() {
    for (;;) {
    }
}

static void task_notify() {
    for (;;) {
    }
}