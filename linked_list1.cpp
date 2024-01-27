#include <bits/stdc++.h>
using namespace std;

//creating a class
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//insertion function at head  // Insert at beginning
void insertAthead(Node* &head,int data){      //why we use reference..?? --- we don't want to make copy, we can change in our original linked list

    //new node create for that data
    Node* tmp = new Node(data);   

    //that node's pointer points to head
    tmp->next = head;

    //& next that node become our head
    head = tmp;
}

//traverse a linked list
void print(Node* &head){

    //creating a node which is pointing to head
    Node* tmp = head;
    
    //traverse while that node not become NULL
    while(tmp != NULL){
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
}


//insertion fuction at tail  // Insert at end
void insertAttail(Node* &tail,int data){

    //creating a node for data
    Node* tmp = new Node(data);

    //pointing tail pointer to that data node
    tail->next = tmp;

    // & now that node become our tail
    tail = tmp;
}

//insert at ith position
void insertAtithPosition(Node* &head,Node* &tail,int position,int data){
    
    //node which points to head
    Node* tmp = head;

    //traverse till ith position
    int cnt = 1;
    while(cnt<position-1){
        tmp = tmp->next;
        cnt++;
    }

    // check if insert at last node
    int flag = 0;
    if(tmp->next==NULL){
        flag = 1;
    }


    //creating a node for data which insert
    Node* node1 = new Node(data);

    //that node points to ith position->next
    node1->next = tmp->next;

    //our tmp node points to that node
    tmp->next = node1;


    if(flag==1){
        tail = node1;
    }
}



int main(){
    
    //Creating object
    Node* node1 = new Node(10);
    cout<< node1->data <<endl;
    cout<< node1->next <<endl;

    //pointing head to our node1
    Node* head = node1;

    //pointing tail to our node1
    Node* tail = node1;

    //creating a singly linked list, node inserting at head
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        insertAthead(head,a[i]);
    }
    
    print(head);
    cout<<endl;

    //creating a singly linked list, node inserting at tail
    int n1;
    cin>>n1;
    int b[n1];
    for(int i=0;i<n1;i++){
        cin>>b[i];
        insertAttail(tail,b[i]);
    }
    insertAtithPosition(head,tail,9,700);
    print(head);
    cout<<endl;
}