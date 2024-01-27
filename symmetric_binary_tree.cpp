#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left, *right;
};
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}
bool issymmetry(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1->data!=root2->data){
        return false;
    }else{
       return (issymmetry(root1->left,root2->right) && issymmetry(root1->right,root2->left));
    }
    return true;
}
 int main(){
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(3);
    if(issymmetry(root,root)==1){
        cout<<"symmetry";
    }else{
        cout<<"not symmetry";
    }
}