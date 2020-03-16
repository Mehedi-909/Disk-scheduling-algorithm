#include <iostream>

#define MAXSIZE 199

using namespace std;


void c_scan(bool queue[], int numberOfProcess, int initialHeadPosition) {

    for (int i = initialHeadPosition; i < MAXSIZE; i++) {
        if (queue[i])
            cout << i << " ";
    }

    int breakingPoint;

    for (int i = 0; i < initialHeadPosition - 1; i++) {
        if (queue[i]) {
            cout << i << " ";
            breakingPoint = i;
        }

    }

    cout << endl;

    cout << "Total seeking time : " << (MAXSIZE - initialHeadPosition) + (MAXSIZE - 0) + (breakingPoint - 0) << endl;


}

int main() {
    bool queue[MAXSIZE];
    int numberOfProcess, initialHeadPosition;

    for (int i = 0; i < MAXSIZE; i++)
        queue[i] = false;

    cout << "Enter number of process: ";
    cin >> numberOfProcess;

    cout << "Enter initial head position: ";
    cin >> initialHeadPosition;

    cout << "Enter queue" << endl;

    for (int i = 0; i < numberOfProcess; i++) {
        int process;
        cin >> process;
        queue[process] = true;
    }

    c_scan(queue, numberOfProcess, initialHeadPosition);
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