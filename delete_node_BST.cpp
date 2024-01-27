#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* insert(node *root,int key){
    
    if(root==NULL){
        node* temp=new node;
        temp->data=key;
        temp->left=temp->right=NULL;
        return temp;
    }
    if(key<root->data){
        root->left=insert(root->left,key);
    }else{
        root->right=insert(root->right,key);
    }
    return root;

}
void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* minValuenode(node* root){
    node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* Delete(node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=Delete(root->left,key);
    }else if(key>root->data){
        root->right=Delete(root->right,key);
    }else{
        //case:1 no children 
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        //case:2 one childrem
        else if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        //case:3 two children
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        node* temp=minValuenode(root->right);
        root->data=temp->data;
        root->right=Delete(root->right,temp->data);
    }
    return root;
}
 int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node *root=NULL;
    root=insert(root,a[0]);
    for(int i=1;i<n;i++){
        insert(root,a[i]);
    }
    inorder(root);
    cout<<endl;
    Delete(root,16);
    inorder(root);
    cout<<endl;
 } 