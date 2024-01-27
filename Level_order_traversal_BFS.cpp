#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

void levelorder(node* root){ 
    if(root==NULL){
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
            node *curr=q.front();
            q.pop();
            if(curr->left!=0){
                q.push(curr->left);
            }
            if(curr->right!=0){
                q.push(curr->right);
            }
            cout<<curr->data<<" ";    
    }
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* newNode(int data){
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int main(){
node *root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(3);
   root->left->left=newNode(4);
   root->left->right=newNode(5);
   root->left->right->left=newNode(6);
   root->right->left=newNode(7);
   root->right->right=newNode(8);
   root->right->right->left=newNode(9);
   root->right->right->right=newNode(10);

   levelorder(root);
   cout<<endl;
   preorder(root);
   cout<<endl;
   inorder(root);
   return 0;
}