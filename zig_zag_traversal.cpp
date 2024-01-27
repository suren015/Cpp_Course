#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
void zigzag(node* root){
    if(root==NULL){
        return;
    }
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node* temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left!=0){
                s2.push(temp->left);
            }
            if(temp->right!=0){
                s2.push(temp->right);
            }
        }
        while(!s2.empty()){
            node* temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->right!=0){
                s1.push(temp->right);
            }
            if(temp->left!=0){
                s1.push(temp->left);
            }
        }
    }

}
    
node* newnode(int data){
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main(){
    node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->right=newnode(6);
    zigzag(root);
}