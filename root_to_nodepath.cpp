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
bool haspath(node* root,int x,vector<int>&v){
    if(root==NULL){
        return false;
    }
    v.push_back(root->data);
    if(root->data==x){
        return true;
    }
    if(haspath(root->left,x,v) || haspath(root->right,x,v)){
        return true;
    }
    v.pop_back();
    return false;
}
void rootToNode(node* root,int x){
    vector<int>v;
    if(haspath(root,x,v)){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }else{
        cout<<" NO path"<<endl;
    }
}

int main(){
    int x;
    cin>>x;
   node* root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(3);
   root->left->left=newNode(4);
   root->left->right=newNode(5);
   root->left->right->left=newNode(6);
   root->left->right->right=newNode(7);
   
   rootToNode(root,x);
   return 0;
}