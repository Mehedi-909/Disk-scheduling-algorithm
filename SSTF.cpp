#include <bits/stdc++.h>

#define MAXSIZE 200

using namespace std;

void sstf(int sizeOfQueue, int queue[], int initialHeadPosition) {
    int startingHeadPositionIndex;

    for (int i = sizeOfQueue - 1; i >= 0; i--) {
        if (queue[i] <= initialHeadPosition) {
            startingHeadPositionIndex = i;
            break;
        }
    }

    for (int i = startingHeadPositionIndex; i >= 0; i--)
        cout << queue[i] << " ";

    for (int i = startingHeadPositionIndex + 1; i < sizeOfQueue; i++)
        cout << queue[i] << " ";

    int seekingTime = (initialHeadPosition - queue[0]) + (queue[sizeOfQueue - 1] - queue[0]);

    cout << endl << "Total seeking time : " << seekingTime << endl;

}

int main() {
    int numberOfProcess, queue[MAXSIZE], initialHeadPosition;

    cout << "Enter number of process: ";
    cin >> numberOfProcess;

    cout << "Enter initial head position : ";
    cin >> initialHeadPosition;

    cout << "Enter queue" << endl;
    for (int i = 0; i < numberOfProcess; i++)
        cin >> queue[i];


    sort(queue, queue + numberOfProcess);

    sstf(numberOfProcess, queue, initialHeadPosition);


    return 0;
}

/*
input
----------------------------------
Enter number of process: 7
Enter initial head position : 50
Enter queue
82 170 43 140 24 16 190

output
----------------------------------
43 24 16 82 140 170 190
Total seeking time : 208

----------------------------------
sample input
7
50
82 170 43 140 24 16 190
 */
