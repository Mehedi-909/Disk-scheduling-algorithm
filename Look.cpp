#include <iostream>

#define MAXSIZE 199

using namespace std;

int minValue(bool queue[]) {
    for (int i = 0; i < MAXSIZE; i++)
        if (queue[i])
            return i;
}

int maxValue(bool queue[]) {
    for (int i = MAXSIZE - 1; i >= 0; i--)
        if (queue[i])
            return i;
}

void look(bool queue[], int numberOfProcess, int initialHeadPosition) {

    int max = maxValue(queue);

    for (int i = initialHeadPosition; i < max; i++) {
        if (queue[i])
            cout << i << " ";
    }

    int min = minValue(queue);

    for (int i = initialHeadPosition - 1; i >= min; i--) {
        if (queue[i])
            cout << i << " ";
    }

    cout << endl;

    cout << "Total seeking time : " << (max - initialHeadPosition) + (max - min) << endl;


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

    look(queue, numberOfProcess, initialHeadPosition);
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