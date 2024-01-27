/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* newnode(int key){
    node* temp=new node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
node* insert(node* root,int elem){
    if(root==NULL){
        node* temp=new node;
        temp->data=elem;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(root->data>elem){
        root->left=insert(root->left,elem);
    }else{
        root->right=insert(root->right,elem);
    }
    return root;
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,a[i]);
    }
    inorder(root);
}
