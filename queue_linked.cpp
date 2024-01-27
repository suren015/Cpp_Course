#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
}*front=NULL,*rear=NULL;
void enqueue(int x){
    node* t=new node;
    if(t==NULL){
        cout<<"queue is full"<<endl;
    }else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
           front=rear=t;
        }else{
            rear->next=t;
            rear=t;
        }
    
    }
    
}
void dequeue(){
    if(front==NULL){
        cout<<"Queue is empty"<<" ";
    }else{
         node* p=front;
    cout<<p->data<<endl;
    front=front->next;
    }
   
}
void display(){
    node *p=front;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        enqueue(x);
    }
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
}