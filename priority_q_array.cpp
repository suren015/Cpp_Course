// C++ program to implement Priority Queue using Arrays
#include <bits/stdc++.h>
using namespace std;
struct item{
    int value;
    int priority;
};
item pr[10000];
int size=-1;
void enqueue(int value,int priority){
     size++;
     pr[size].value=value;
     pr[size].priority=priority;
}
int peek(){
    int max_priority=INT_MIN;
    int ind=-1;
    for(int i=0;i<=size;i++){
        if(max_priority<pr[i].priority){
            max_priority=pr[i].priority;
            ind=i;
        }else if(max_priority==pr[i].priority && ind>-1 && pr[ind].value<pr[i].value){
            max_priority=pr[i].priority;
            ind=i;
        }
    }
    return ind;
}
void Dequeue(){
    int ind=peek();
    for(int i=ind;i<size;i++){
        pr[i]=pr[i+1];
    }
    size--;
}
int main(){
    for(int i=0;i<4;i++){
        int x,y;  //element and their priority
        cin>>x>>y;
        enqueue(x,y);
    }

    //stores the top element
    int ind=peek();
    cout<<pr[ind].value<<endl;
    Dequeue();
    ind=peek();
    cout<<pr[ind].value<<endl;
}