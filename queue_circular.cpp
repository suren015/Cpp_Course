#include <bits/stdc++.h>
using namespace std;

class Queue{
    int front,rear;
    int size;
    int *arr;

    public:
    Queue(int n){
        front = rear = -1;
        size = n;
        arr = new int[n];
    }
    void Enqueue(int val);
    int deQueue();
    void display();

};

void Queue::Enqueue(int x){
    if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
        cout<<"QUEUE FULL"<<endl;
        return;
    }else if(front == -1){
        front = rear = 0;
        arr[front] = x;
    }else{
        if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = x;
        }else{
            rear++;
            arr[rear] = x;
        }
    }
    return;
}

int Queue:: deQueue(){
    if(front == -1){
        cout<<"QUEUE EMPTY"<<endl;
        return -1;
    }
    int data = arr[front];
    arr[front] = -1;
    if(front == rear){
        front = -1;
        rear = -1;
    }else if(front == size-1){
        front = 0;
    }else{
        front++;
    }
    return data;
}

void Queue:: display(){
    if(front==-1){
        cout<<"QUEUE EMPTY"<<endl;
        return;
    }
    if(rear >= front){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }else{
        for(int i=front;i<size;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    Queue q(5);

    // Inserting elements in Circular Queue
    q.Enqueue(14);
    q.Enqueue(22);
    q.Enqueue(13);
    q.Enqueue(-6);
  
    // Display elements present in Circular Queue
    q.display();

    // Deleting elements from Circular Queue
    cout<< q.deQueue()<<endl;
    cout<< q.deQueue()<<endl;
  
    q.display();
  
    q.Enqueue(9);
    q.Enqueue(20);
    q.Enqueue(5);
  
    q.display();
  
    q.Enqueue(20);
    return 0;
}