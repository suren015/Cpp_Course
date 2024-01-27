#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* newnode(int key){
    node* temp = new node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}

node* fun(node* root,int key){
    if(root==NULL){
        node *temp=newnode(key);
        return temp;
    }
      if(root->data>key){
        root->left=fun(root->left,key);
      }else{
        root->right=fun(root->right,key);
      }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node* root=newnode(a[0]);
    for(int i=1;i<n;i++){
        fun(root,a[i]);
    }
    inorder(root);
}