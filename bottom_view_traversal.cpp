#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
void printbottomview(node* root){
    if(root==NULL){
        return;
    }
    queue<pair<node*,int>>q;
    map<int,int>m;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        node* curr=it.first;
        int line=it.second;
        m[line]=curr->data;
        if(curr->left!=0){
            q.push({curr->left,line-1});
        }
        if(curr->right!=0){
            q.push({curr->right,line+1});
        }
    }
    // map<int,int>::iterator it;
    // for(it=m.begin();it!=m.end();it++){
    //     cout<<it->second<<" ";
    // }
    for(auto &it : m){
        cout<<it.second<<" ";
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
    root->left->right->left=newnode(8);
    root->left->right->right=newnode(9);
    root->right->right=newnode(7);
    printbottomview(root);
}    