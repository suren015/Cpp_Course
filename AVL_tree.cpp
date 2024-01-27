#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
     node* left;
     node* right;
     int height;
};

int height(node* p){
    if(p==NULL){
        return 0;
    }
    return p->height;
}

int getBalance(node *p){
    if(p==NULL){
        return 0;
    }
    return height(p->left)-height(p->right);
}

node* rightRotate(node* y){
     node* x=y->left;
     node* T2=x->right;

     //perform rotation
     x->right=y;
     y->left=T2;

     y->height=max(height(y->left),height(y->right))+1;
     x->height=max(height(x->left),height(y->right))+1;

     return x;
}

node* leftRotate(node* x){
    node *y = x->right;
    node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
 
    // Return new root
    return y;
}
node* insert(node* p,int key){
      if(p==NULL){
        node* temp=new node;
        temp->data=key;
        temp->left=temp->right=NULL;
        temp->height=1;
        return temp;
      }
      if(key<p->data){
        p->left=insert(p->left,key);
      }else if(key>p->data){
        p->right=insert(p->right,key);
      }else{
        return p;
      }
      //update height of this ancestor node
      p->height=1+max(height(p->left),height(p->right));

      //get balance factor
      int balance=getBalance(p);

      if(balance>1 && key<p->left->data){
        return rightRotate(p);
      }
      if(balance<-1 && key>p->right->data){
        return leftRotate(p);
      }
      if (balance > 1 && key > p->left->data){
        p->left = leftRotate(p->left);
        return rightRotate(p);
      }
      if (balance < -1 && key < p->right->data){
        p->right = rightRotate(p->right);
        return leftRotate(p);
      }
      return p;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);

    preorder(root);
    return 0;
}