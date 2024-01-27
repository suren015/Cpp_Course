#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

bool are_identical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }else if(root1==NULL || root2==NULL){
        return false;
    }

    return (root1->data==root2->data) && are_identical(root1->left,root2->left) && are_identical(root1->right,root2->right);
   
}

node* newNode(int data){
    node* temp;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
 int main(){
    node *root1=newNode(1);
    
    root1->left=newNode(2);
    root1->right=newNode(3);
    root1->right->left=newNode(4);
    root1->right->right=newNode(5);

    node *root2=newNode(1);

    root2->left=newNode(2);
    root2->right=newNode(3);
    root2->right->left=newNode(4);
    root2->right->right=newNode(5);

    if(are_identical(root1,root2)){
        cout<<"TREES are identical"<<endl;
    }else{
        cout<<"TREES are not identical";
    }
 }