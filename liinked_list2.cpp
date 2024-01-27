#include <bits/stdc++.h>
using namespace std;

//creat class of node
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

//Insertion
void insert(Node* &tmp,int data){
    Node* node = new Node(data);
    tmp->next = node;
    tmp = node;
}

//deletion
void delete1(Node* &head,Node* &tmp,int key){
    if(tmp->data==key){
        head = head->next;
        tmp->next = NULL;
        return;
    }

    while(tmp->next->data!=key){
        tmp=tmp->next;
    }
    Node* curr = tmp->next;
    tmp->next = curr->next;

}

//traverse and print the nodes
void print(Node* &head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    Node* head = new Node(a[0]);
    Node* tmp = head;
    for(int i=1;i<n;i++){
        insert(tmp,a[i]);
    }
    
    int k;
    cin>>k;
    Node* tmp1 = head;
    delete1(head,tmp1,k);
    print(head);
}