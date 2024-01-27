#include <bits/stdc++.h>
using namespace std;
#define size 10
struct node{
    int data;
    node* next;
};

void insert(int key,node *hash[],int n){
    node* temp=new node;
    temp->data=key;
    temp->next=NULL;

    key=key%10;
    if(hash[key]==NULL){
        hash[key]=temp;
    }else{
        node* t=hash[key];
        while(t->next){
            t=t->next;
        }
        t->next=temp;
    }
}
void print(node* hash[],int n){
    for(int i=0;i<10;i++){
        node* temp=hash[i];
        cout<<"hash["<<i<<"]";
        while(temp!=NULL){
            cout<<"-->"<<temp->data;
            temp=temp->next;
        }
        cout<<"\n";
    }
}
int search(int key,node* hash[],int n){
    int value=key;
    key=key%10;
    node* temp=hash[key];
    if(temp->data==value){
        return 1;
    }else{
        while(temp->next!=NULL){
        if(temp->data==value){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
    }
    
}

int main(){
    node* hash[10];
    for(int i=0;i<10;i++){
        hash[i]=NULL;
    }
   int a[]={114,15,19,24,53,62,81,46,2,8,47};
   int n=sizeof(a)/sizeof(a[0]);
   int m=*max_element(a,a+n);
   
   for(int i=0;i<n;i++){
    insert(a[i],hash,m+1);
   }
   print(hash,10);
   //searching an element
   if(search(24,hash,10)){
    cout<<"search found"<<endl;
   }else{
    cout<<"no found"<<endl;
   }

}