#include<bits/stdc++.h>
#define N 200
using namespace std;

int minimumIndex(int a[N]){

    int min = 10000;
    int index;
    for (int i = 0; i < N; i++){

        if (min > a[i]){
           min = a[i];
            index=i;
        }
    }
    return index;
}

int maxIndex(int a[N]){

    int max = 0;
    int index;
    for (int i = 0; i < N; i++){

        if (max < a[i]){
           max = a[i];
            index=i;
        }
    }
    return index;
}

int main(){

    int numOfRequest;
    int requestA[N];
    queue <int> request;
    for(int i=0;i<N;i++){
        requestA[i]=0;
    }
    cout<<"Enter number of requests:"<<endl;
    cin>>numOfRequest;
    cout<<"Enter request id: "<<endl;
    for(int i=0;i<numOfRequest;i++){
        //cin>>request[i];
        int r;
        cin>>r;
        requestA[r]=r;
        request.push(r);
    }
    int min=minimumIndex(requestA);
    int max=maxIndex(requestA);
    cout<<"Enter starting point:"<<endl;
    int start;
    cin>>start;
    cout<<"Select one method from below and enter the number:"<<endl;
    cout<<"1.FCFS   2.SSTF  3.SCAN  4.CSCAN    5.LOOK"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
    case 1:

            while (!request.empty()) {
                cout << '\t' << request.front();
                request.pop();
            }
        cout << '\n';


    break;

    case 2:
        cout<<"nothing"<<endl;
    break;

    case 3:
        for(int i=start;i<N;i++){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }

        for(int i=start-1;i>=min;i--){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }
    break;

    case 4:
        for(int i=start;i<N;i++){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }

        for(int i=0;i<start;i++){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }
    break;

    case 5:
        for(int i=start;i<=max;i++){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }

        for(int i=start-1;i>=min;i--){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }
    break;

    default:
        cout<<"Invalid input"<<endl;
        break;
    }
return 0;
}
