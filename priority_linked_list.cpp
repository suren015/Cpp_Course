#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int priority;
    node* next;
};
node* newnode(int d,int p){
    node* temp=new node;
    temp->data=d;
    temp->priority=p;
    temp->next=NULL;
    return temp;
}
int peek(node **head){
    return (*head)->data;
}
void pop(node **head){
    node *temp=*head;
    (*head)=(*head)->next;
    free(temp);
}
void push(node **head,int d,int p){
    node* start=(*head);
    node* temp=newnode(d,p);
    if((*head)->priority>p){
        temp->next=(*head);
        (*head)=temp;
    }else{
        while(start->next!=NULL && start->priority<p){
            start=start->next;
        }
        temp->next=start->next;
        start->next=temp;
    }

}
int isEmpty(node **head){
    return (*head)==NULL;
}
int main(){
    node* root=newnode(4,1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        push(&root,x,y);
    }
    while(!isEmpty(&root)){
        cout<<" "<<peek(&root);
        pop(&root);
    }
}