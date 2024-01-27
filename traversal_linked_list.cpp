#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
int main(){
    node* A;
    A=NULL;
    //adding an element by traversing
    node* temp=new node();
    temp->data=2;
    temp->next=NULL;
    A=temp;
    // while(temp!=0){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }

    //adding one other element by traversing
    temp=new node();
    temp->data=4;
    temp->next=NULL;
     node* temp1=A;
     while(temp1!=NULL){
         cout<<temp1->data<<" ";
         temp1=temp1->next;
     }

}