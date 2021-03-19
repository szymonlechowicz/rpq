#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "rpq.h"
#include "schrage.h"

using namespace std;

int main()
{
    string s;
    int sum = 0;
    int cmax;

    clock_t t;
    t = clock();
    ifstream file("data.txt");
    for (int f = 1; f <= 4; f++)
    {
        while (s != "data." + to_string(f)) file >> s;

        int n = 0;
        file >> n;

        QueueTask queue;
        Task* task = new Task[n];
        for (int i = 0; i < n; i++)
        {
            file >> task[i].r;
            file >> task[i].p;
            file >> task[i].q;
            task[i].order = i + 1;
            queue.push(task[i]);
        }

        //cmax = SortR(queue);
        //cmax = schrage(queue,task);
        cmax = schrage_prmt(queue);

        cout << "Time" << f << ":\t" << cmax << endl;
        sum += cmax;

        //permutationR(queue);
        //permutationSchrage(task, n);

    }
    t = clock() - t;
    cout << "Total time:\t" << sum << endl;
    cout << "Program time: \t" << ((float)t) / CLOCKS_PER_SEC << " s" << endl;


}