#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};



node* newNode(int data){
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* lowestCommonAncestor(node* root,node* p, node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    node* left=lowestCommonAncestor( root->left, p, q);
    node* right=lowestCommonAncestor( root->right, p, q);
    if(left==NULL){
        return right;
    }else if(right==NULL){
        return left;
    }else{
        return root;
    }
}

node* findNode(node* root,int data){
    if(root==NULL)
        return NULL;
    if(root->data==data)
        return root;
    node* left = findNode(root->left,data);
    if(left!=NULL)
        return left;
    return findNode(root->right,data);
}

int main(){
    int x,y;
    cin>>x>>y;
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
   node* first = findNode(root,x);
   node* second = findNode(root,y);
   node * k = lowestCommonAncestor(root,first,second);
   cout<<k->data<<endl;
}