#include <bits/stdc++.h>
using namespace std;
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int[size];
}
void enqueue( Queue *q,int x){
    if(q->rear==q->size-1){
        cout<<"Queue is full"<<endl;
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
void display( Queue q){
    for(int i=q.front+1;i<=q.rear;i++){
        cout<<q.Q[i]<<" ";
    }
}
 int main(){
    Queue q;
    int n;
    cin>>n;
    // create(&q,n);
    q.size=n;
    q.front=-1;
    q.rear=-1;
    q.Q=new int[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        enqueue(&q,x);
    }
    display(q);

 }