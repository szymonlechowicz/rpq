#pragma once

#include "rpq.h"

int schrage(QueueTask qn, Task* tasks)
{
    int t = 0;
    int i = 0;
    int cmax = 0;
    ReadyQueueTask ready;
    Task e;

    while (!qn.empty() || !ready.empty())
    {
        while (!qn.empty() && (qn.top().r <= t))
        {
            e = qn.top();
            ready.push(e);
            qn.pop();
        }
        if (ready.empty())
        {
            t = qn.top().r;
        }
        else
        {
            e = ready.top();
            ready.pop();
            tasks[i] = e;
            i++;
            t += e.p;
            cmax = max(cmax, t + e.q);
        }
    }
    return cmax;
}

int schrage_prmt(QueueTask qn)
{
    int t = 0;
    int i = 0;
    int cmax = 0;
    ReadyQueueTask ready;
    Task e;
    Task l;
    l.q = INT_MAX;
    l.p = 0;
    l.r = 0;

    while (!qn.empty() || !ready.empty())
    {
        while (!qn.empty() && (qn.top().r <= t))
        {
            e = qn.top();
            qn.pop();
            ready.push(e);
            if (e.q > l.q)
            {
                l.p = t - e.r;
                t = e.r;
                if (l.p > 0)
                {
                    ready.push(l);
                }
            }
        }
        if (ready.empty())
        {
            t = qn.top().r;
        }
        else
        {
            e = ready.top();
            ready.pop();
            l = e;
            t += e.p;
            cmax = max(cmax, t + e.q);
        }
    }

    return cmax;
}

int SortR(QueueTask qn)
{
    int t = 0, cmax = 0;
    while (!qn.empty())
    {
        t = max(t, qn.top().r) + qn.top().p;
        cmax = max(cmax, t + qn.top().q);
        qn.pop();
    }
    return cmax;
}

void permutationR(QueueTask qn)
{
    while (!qn.empty())
    {
        cout << qn.top().order << " ";
        qn.pop();
    }
    cout << endl;
}

void permutationSchrage(Task* task, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << task[i].order << " ";
    }
    cout << endl;
}