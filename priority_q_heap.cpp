// C++ code to implement priority-queue
// using array implementation of
// binary heap

#include <bits/stdc++.h>
using namespace std;
int size=-1;
int H[100000];


void insert(int priority){
     size++;
     H[size]=priority;
     int i=size;
     while(i>0 && H[(i-1)/2]<H[i]){
        swap(H[(i-1)/2],H[i]);
        i=(i-1)/2;
    }
     
}
void Delete(int i){
    cout<<H[i]<<endl;
    size--;
    for(int i=0;i<=size;i++){
        H[i]=H[i+1];
    }
}
int main(){
    
    /*         45
            /      \
           31      14
          /  \    /  \
         13  20  7   11
        /  \
       12   7
    Create a priority queue shown in
    example in a binary max heap form.
    Queue will be represented in the
    form of array as:
    45 31 14 13 20 7 11 12 7 */
 
    // Insert the element to the
    // priority queue
    
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);
    cout<<"Priority queue before extracting the max element"<<endl;
    for(int i=0;i<=size;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
    cout<<"node with max priority"<<endl;
    int i=0;
    Delete(i);
    for(int i=0;i<=size;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}