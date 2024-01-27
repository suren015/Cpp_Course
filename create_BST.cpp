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
 } 