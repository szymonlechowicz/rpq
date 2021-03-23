#pragma once
#include <queue>
#include <vector>

using namespace std;

struct Task
{
    int r;
    int p;
    int q;
    int order;
};

// priority: min r AND p !
struct CompareR
{
    bool operator ()(const Task& task1, const Task& task2)
    {
        if (task1.r > task2.r) return true;
        if (task1.r < task2.r) return false;
        if (task1.p > task2.p) return true;
        if (task1.p < task2.p) return false;
        return false;
    }
};

// priority: max
struct CompareQ
{
    bool operator ()(const Task& task1, const Task& task2)
    {
        if (task1.q > task2.q) return false;
        if (task1.q < task2.q) return true;
        return false;
    }
};

typedef priority_queue <Task, vector<Task>, CompareR> QueueTask;
typedef priority_queue <Task, vector<Task>, CompareQ> ReadyQueueTask;