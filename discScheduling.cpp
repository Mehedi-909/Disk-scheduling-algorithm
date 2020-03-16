#include<bits/stdc++.h>
#define N 200
using namespace std;
int minimum,maximum;
int start;


int minimumIndex(int a[N]){

    int minimum = 10000;
    int index;
    for (int i = 0; i < N; i++){

        if (minimum > a[i]){
           minimum = a[i];
            index=i;
        }
    }
    return index;
}

int maximumIndex(int a[N]){

    int maximum = 0;
    int index;
    for (int i = 0; i < N; i++){

        if (maximum < a[i]){
           maximum = a[i];
            index=i;
        }
    }
    return index;
}

void FCFS(queue <int> request){
    cout<<"FCFS processing serial : "<<endl;
    while (!request.empty()) {
                cout << '\t' << request.front();
                request.pop();
            }
        cout << '\n';

}

void SCAN(int requestA[N]){

    cout<<"SCAN processing serial : "<<endl;
    for(int i=start;i<N;i++){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }

        for(int i=start-1;i>=minimum;i--){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }
    cout << '\n';
}

void CSCAN(int requestA[N]){
    cout<<"CSCAN processing serial : "<<endl;
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
    cout << '\n';
}

void LOOK(int requestA[N]){

    cout<<"LOOK processing serial : "<<endl;
    for(int i=start;i<=maximum;i++){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }

        for(int i=start-1;i>=minimum;i--){
            if(requestA[i]!=0){
                cout<<requestA[i]<<'\t';
            }
        }
    cout << '\n';
}

void SSTF(int requestA[N],int numOfRequest){

    cout<<"SSTF processing serial : "<<endl;
    int previous=0,next=0;
    int count=0;

    //cout<<start;
        requestA[start]=0;

    while(count<numOfRequest){

        for(int i=start;i<=maximum ;i++){
            if(requestA[i]!=0){
                next=requestA[i];
               // cout<<next<<endl;
                break;
            }
            else{
                next=0;
            }
        }

        for(int i=start-1;i>=minimum ;i--){
            if(requestA[i]!=0){
                previous=requestA[i];
                //cout<<previous<<endl;
                break;
            }
            else{
                previous=10000;
            }
        }

        int a=abs(start-previous);
        int b=abs(next-start);


        if(a<b){
            cout<<'\t'<<previous;
            count++;
            requestA[previous]=0;
            start=previous;

        }
        else{
            cout<<'\t'<<next;
            count++;
            requestA[next]=0;
            start=next;

        }

    }

    cout << '\n';
}


int main(){


    int requestA[N];
    queue <int> request;
    for(int i=0;i<N;i++){
        requestA[i]=0;
    }
    int numOfRequest;
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
    minimum=minimumIndex(requestA);
    maximum=maximumIndex(requestA);
    cout<<"Enter starting point:"<<endl;
    cin>>start;

        FCFS(request);
       SCAN(requestA);
       CSCAN(requestA);
       LOOK(requestA);
       SSTF(requestA,numOfRequest);

return 0;
}
