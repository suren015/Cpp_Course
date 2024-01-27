#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node*right;
};
void printboundaryleft(node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=0){
        cout<<root->data<<" ";
        printboundaryleft(root->left);
    }else if(root->right!=0){ 
        cout<<root->data<<" ";
        printboundaryleft(root->right);
    }
}

void printleaf(node* root){
    if(root==NULL){
        return;
    }
    printleaf(root->left);
    if(!(root->left) && !(root->right)){
        cout<<root->data<<" ";
        printleaf(root->right);
    }
}

void bound_trav(node* root){
    if(root==null){
        return;
    }
    cout<<root->data<<" ";
    printBoundaryleft(root->left);
    printleaf(root->left);
    printleaf(root->right);
}
node* newNode(int data){
    node* temp=new node;
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
   
   
}