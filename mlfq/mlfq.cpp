/*
多级反馈队列（MLFQ）的基本规则

    如果A的优先级 > B的优先级，运行A（不运行B）
    如果A的优先级 = B的优先级，A和B通过RR规则运行
    工作进入系统时，放在最高优先级队列
    一旦工作用完了其在某一层中的时间配额（每一层时间配额的计算为当前优先级+1，例如0优先级队列的时间配额为1），就放入优先级低一级的队列
    经过一段时间RESET，就将系统中所有工作重新加入最高优先级队列

*/

#include <iostream>
#include <queue>
#include <unistd.h>
using namespace std;

// MLFQ的队列数量
#define QUEUE_NUMBER 3
// 测试中的job数量
#define JOB_NUMBER 5
// 到达25s就进行RESET操作，将系统中所有工作重新加入最高优先级队列
#define RESET 20
// 是否间隔1s显示
#define INTERVAL 0


// job结构体
typedef struct job
{
    // job的id
    int job_id;
    // 任务当前所在的队列
    int current_queue;
    // 任务在当前队列已经运行的时间
    int current_queue_run_time;
    // 任务需要运行的总时间
    int total_time;
    // 任务已经运行的总时间
    int total_run_time;
} job_t;

// 从当前队列中挑选优先级最高的job，如果同一队列则RR选择
void choose_job();
// 调度job
void schedule();
// 判断是否需要reset
void judge_reset();
// 五个任务0时刻同时到达测试
void test1();
// 五个任务不同时刻到达测试
void test2();

// 系统当前运行时间，超过RESET时间就重置为0
int run_time = 0;
// 所有任务的结构体
job_t jobs[JOB_NUMBER];
job_t *current = NULL;
queue<job_t *> MLFQ_queue[QUEUE_NUMBER];

int main()
{
    test1();

    run_time = 0;

    test2();
}

void test1()
{
    // 初始化测试任务，一共五个任务，每个任务需要的时间为 3+i*3
    cout << "--------------" << endl;
    cout << "Test 1 begin: " << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < JOB_NUMBER; i++)
    {
        jobs[i].job_id = i;
        jobs[i].current_queue = jobs[i].current_queue_run_time = jobs[i].total_run_time = 0;
        jobs[i].total_time = i * 3 + 3;

        MLFQ_queue[0].push(&jobs[i]);
    }

    // 不停调度
    while (true)
    {
        schedule();

        if (current == NULL)
        {
            break;
        }

        cout << "System time: " << run_time << "\tCurrent job id: " << current->job_id << "\tCurrent queue: " << current->current_queue
             << "\tTotal time: " << current->total_time << "\tCurrent run time " << current->total_run_time
             << "\tCurrent queue run time " << current->current_queue_run_time << endl;

        run_time++;
        current->total_run_time++;
        current->current_queue_run_time++;

        if (current->total_run_time >= current->total_time)
        {
            cout << "Job " << current->job_id << " finished" << endl;
            current = NULL;
        }

        judge_reset();
        if(INTERVAL)
            sleep(1);
    }

    cout << "--------------" << endl;
    cout << "Test 1 finished: " << endl;
    cout << "--------------" << endl;
}

void test2()
{
    // 初始化测试任务，一共五个任务，每个任务需要的时间为 3+i*3
    cout << "--------------" << endl;
    cout << "Test 2 begin: " << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < JOB_NUMBER; i++)
    {
        jobs[i].job_id = i;
        jobs[i].current_queue = jobs[i].current_queue_run_time = jobs[i].total_run_time = 0;
        jobs[i].total_time = i * 3 + 3;
    }

    // 不停调度，每个任务到达时间不通
    while (true)
    {
        if (run_time == 0)
        {
            cout << "Job 0,1 reached" << endl;
            MLFQ_queue[0].push(&jobs[0]);
            MLFQ_queue[0].push(&jobs[1]);
        }

        if (run_time == 3)
        {
            cout << "Job 2,3 reached" << endl;
            MLFQ_queue[0].push(&jobs[2]);
            MLFQ_queue[0].push(&jobs[3]);
        }

        if (run_time == 5)
        {
            cout << "Job 4 reached" << endl;
            MLFQ_queue[0].push(&jobs[4]);
        }

        schedule();

        if (current == NULL)
        {
            break;
        }

        cout << "System time: " << run_time << "\tCurrent job id: " << current->job_id << "\tCurrent queue: " << current->current_queue
             << "\tTotal time: " << current->total_time << "\tCurrent run time " << current->total_run_time
             << "\tCurrent queue run time " << current->current_queue_run_time << endl;

        run_time++;
        current->total_run_time++;
        current->current_queue_run_time++;

        if (current->total_run_time >= current->total_time)
        {
            cout << "Job " << current->job_id << " finished" << endl;
            current = NULL;
        }

        judge_reset();
        if(INTERVAL)
            sleep(1);
    }

    cout << "--------------" << endl;
    cout << "Test 2 finished: " << endl;
    cout << "--------------" << endl;
}

void choose_job()
{
    // 从最高优先级中选择第一个任务进行调度
    for (int i = 0; i < QUEUE_NUMBER; i++)
    {
        if (!MLFQ_queue[i].empty())
        {
            current = MLFQ_queue[i].front();
            MLFQ_queue[i].pop();
            return;
        }
    }
}

void schedule()
{
    // 如果当前没有任务则重新选择
    if (current == NULL)
    {
        choose_job();
        return;
    }

    // 如果当前任务在该优先队列运行时间超过该队列的上限，则降级到下一队列
    if (current->current_queue_run_time >= current->current_queue + 1 && current->current_queue < QUEUE_NUMBER - 1)
    {
        cout << "Job " << current->job_id << " decrease to queue " << current->current_queue + 1 << endl;
        current->current_queue_run_time = 0;
        current->current_queue++;
        MLFQ_queue[current->current_queue].push(current);
        current = NULL;
        choose_job();
        return;
    }

    // 如果当前任务没有超过当前队列的运行时间上限，根据RR调度重新选择任务，如果新来一个任务，则也会被首先调度
    if (MLFQ_queue[0].empty() && !MLFQ_queue[current->current_queue].empty())
        cout << "Round Robin change " << endl;
    MLFQ_queue[current->current_queue].push(current);
    choose_job();
}

void judge_reset()
{
    if (run_time % RESET == 0)
    {
        cout << "Reset happened: all jobs will be placed in the queue 0" << endl;

        // 所有队列中的任务都加入队列0
        for (int i = 1; i < QUEUE_NUMBER; i++)
        {
            while (!MLFQ_queue[i].empty())
            {
                MLFQ_queue[i].front()->current_queue = 0;
                MLFQ_queue[i].front()->current_queue_run_time = 0;
                MLFQ_queue[0].push(MLFQ_queue[i].front());
                MLFQ_queue[i].pop();
            }
        }

        // 当前运行的任务也加入队列0
        if (current != NULL)
        {
            current->current_queue = 0;
            current->current_queue_run_time = 0;
            MLFQ_queue[0].push(current);
            current = NULL;
        }
    }
}