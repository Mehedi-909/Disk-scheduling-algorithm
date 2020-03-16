#include <iostream>

#define MAXPROCESS 100
using namespace std;

void initializeCompletionsTime(int numOfProcess, int arrivalTime[], int burstTime[], int completionsTime[]) {
    if (numOfProcess <= 0) return;

    int currentTime = arrivalTime[0];

    for (int i = 0; i < numOfProcess; i++) {

        if (currentTime < arrivalTime[i])
            currentTime = arrivalTime[i];

        currentTime += burstTime[i];
        completionsTime[i] = currentTime;
    }
}

void initializeTat(int numOfProcess, int completionsTime[], int arrivalTime[], int tat[]) {
    for (int i = 0; i < numOfProcess; i++)
        tat[i] = completionsTime[i] - arrivalTime[i];

}

void initializeWat(int numOfProcess, int burstTime[], int tat[], int wat[]) {
    for (int i = 0; i < numOfProcess; i++)
        wat[i] = tat[i] - burstTime[i];

}

void print(string text, int numOfProcess, int ara[]) {
    cout << text << " -> ";

    for (int i = 0; i < numOfProcess; i++)
        cout << ara[i] << " ";

    cout << endl << endl;
}

int main() {
    int numOfProcess;
    int arrivalTime[MAXPROCESS], burstTime[MAXPROCESS], completionsTime[MAXPROCESS], tat[MAXPROCESS], wat[MAXPROCESS];

    cout << "Enter number of process: ";
    cin >> numOfProcess;

    cout << "Enter arrivalTime and burstTime i.e(0 2)" << endl;

    for (int i = 0; i < numOfProcess; i++)
        cin >> arrivalTime[i] >> burstTime[i];

    initializeCompletionsTime(numOfProcess, arrivalTime, burstTime, completionsTime);
    print("completionsTime", numOfProcess, completionsTime);

    initializeTat(numOfProcess, completionsTime, arrivalTime, tat);
    print("tat", numOfProcess, tat);

    initializeWat(numOfProcess, burstTime, tat, wat);
    print("wat", numOfProcess, wat);

    return 0;
}
/*
input
---------------------------------------
Enter number of process: 4
Enter arrivalTime and burstTime i.e(0 2)
0 2
1 2
5 3
6 4

output
---------------------------------------
completionsTime -> 2 4 8 12

tat -> 2 3 3 6

wat -> 0 1 0 2

sample input
---------------------------------------
4
0 2
1 2
5 3
6 4
 */
