#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node*right;
};
int max_depth(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=max_depth(root->left);
    int rh=max_depth(root->right);
    return 1+max(lh,rh);
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
   root->right=newNode(3);
   root->right->left=newNode(7);
   root->right->right=newNode(5);
   root->right->right->left=newNode(4);
   root->right->right->right=newNode(10);
   
   cout<<max_depth(root)<<endl;
}