#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};

void preorder(node* root){
    if(root==NULL){
        return;
    }
    stack<node*>s;
    s.push(root);
    while(!s.empty()){
        node *curr=s.top();
        cout<<curr->data<<" ";
        s.pop();
        if(curr->right!=0){
            s.push(curr->right);
        }
        if(curr->left!=0){
            s.push(curr->left);
        }

    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    stack<node*>st;
    node* curr=root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        cout<<curr->data<<" ";
        st.pop();
        curr=curr->right;
    }
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    stack<node*>s1,s2;
    s1.push(root);
    node* curr;
    while(!s1.empty()){
        curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left!=0){
            s1.push(curr->left);
        }
        if(curr->right!=0){
            s1.push(curr->right);
        }
    }
    while(!s2.empty()){
        curr=s2.top();
        s2.pop();
        cout<<curr->data<<" ";
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
   node* root=newNode(10);
   root->left=newNode(8);
   root->right=newNode(2);
   root->left->left=newNode(3);
   root->left->right=newNode(5);
   root->left->right->left=newNode(6);
   root->right->left=newNode(2);
   root->right->right=newNode(8);
   root->right->right->left=newNode(9);
   root->right->right->right=newNode(10);

   preorder(root);
   cout<<endl;
   inorder(root);
   cout<<endl;
   postorder(root);

}