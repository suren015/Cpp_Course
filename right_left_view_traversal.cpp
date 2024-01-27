#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

void leftview(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node *curr=q.front();
        q.pop();
        if(i==0){
            cout<<curr->data<<" ";
        }
    
        if(curr->left!=0){
            q.push(curr->left);
        }
        if(curr->right!=0){
            q.push(curr->right);
        }
        }
        
    }
    
}
void rightview(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
        }
    }
}

node* newNode(int data){
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main(){
   node* root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(4);
   root->left->left=newNode(3);
   root->left->right=newNode(9);
   root->right->left=newNode(5);
   root->right->right=newNode(6);
   root->right->right->right=newNode(7);
   root->right->right->right->right=newNode(10);
   
   leftview(root);
   cout<<endl;
   rightview(root);
   return 0;
}