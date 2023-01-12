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
#include <core/top.h>
#include <types.h>

static void init_thread();
static void task();
static void create_task(uint64_t period, uint64_t time_capacity);

int main() {
    uint32_t tid;
    pok_thread_attr_t tattr;
    memset(&tattr, 0, sizeof(pok_thread_attr_t));

    tattr.period = -1;
    tattr.time_capacity = -1;
    tattr.entry = init_thread;
    pok_thread_create(&tid, &tattr);

    pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
    pok_thread_wait_infinite();
    return 0;
}

static void init_thread() {
    char buf[512];
    for (;;) {
        int buf_idx = 0;
        printf("$ ");
        for (;;) {
            int ch = getch();
            if (ch == '\r' || ch == '\n') {
                printf("\r\n");
                buf[buf_idx] = '\0';
                break;
            } else {
                putch(ch);
                buf[buf_idx++] = (char)ch;
            }
        }
        if (buf_idx == 0) {
            continue;
        }

        if (strcmp("1", buf) == 0) {
            create_task(1000, 100);
        } else if (strcmp("2", buf) == 0) {
            create_task(800, 400);
        } else if (strcmp("3", buf) == 0) {
            create_task(600, 200);
        } else if (strcmp("top", buf) == 0) {
            pok_top();
        } else if (strcmp("help", buf) == 0 || strcmp("h", buf) == 0) {
            printf("Please press 1,2 and 3 to create different tasks,\npress top to show threads,\nand press quit/q to quit.\n");
        }
        
        if (strcmp("quit", buf) == 0 || strcmp("q", buf) == 0) {
            break;
        }
    }

    printf("Please press ctrl+a and x to quit QEMU.\n");
    pok_thread_wait_infinite();
}

static void create_task(uint64_t period, uint64_t time_capacity) {
    pok_thread_attr_t tattr;
    memset(&tattr, 0, sizeof(pok_thread_attr_t));

    tattr.dynamic = TRUE;
    tattr.period = period;
    tattr.time_capacity = time_capacity;
    tattr.entry = task;

    uint32_t tid;
    pok_ret_t ret;
    ret = pok_thread_create(&tid, &tattr);
    if (ret == POK_ERRNO_OK) {
        printf("Thread %u created, period: %u, time capacity: %u.\n",
               (unsigned)tid,
               (unsigned)period,
               (unsigned)time_capacity);
    } else if (ret == POK_ERRNO_TOOMANY) {
        printf("Error: too many thread.\n");
    } else {
        printf("Unknown error occurred.\n");
    }
}

static void task() {
    for (;;) {
    }
}