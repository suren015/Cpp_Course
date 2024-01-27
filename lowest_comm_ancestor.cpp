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
bool haspath(node* root,int t,vector<int>&v){
    if(root==NULL){
        return false;
    }
    v.push_back(root->data);
    if(root->data==t){
        return true;
    }
    if(haspath(root->left,t,v) || haspath(root->right,t,v)){
        return true;
    }
    v.pop_back();
    return false;
}
void rootToNode(node* root,int x,int y){
    vector<int>v1,v2,v3;
    if(haspath(root,x,v1)){
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    if(haspath(root,y,v2)){
        for(int i=0;i<v2.size();i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<v1.size() && i<v2.size();i++){
        if(v1[i]==v2[i]){
            v3.push_back(v1[i]);
        }else{
            break;
        }
    }
    cout<<v3[v3.size()-1]<<endl;
}

int main(){
    int x,y;
    cin>>x>>y;
   node* root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(3);
   root->left->left=newNode(4);
   root->left->right=newNode(5);
   root->left->right->left=newNode(6);
   root->left->right->right=newNode(7);
   root->right->left=newNode(8);
   root->right->right=newNode(9);
   
   rootToNode(root,x,y);
   
   return 0;
}