#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
void func(node* root){
    vector<int>pre,in,post;
    if(root==NULL){
        return;
    }
    stack<pair<node*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }else {
            post.push_back(it.first->data);
        }
    }
    for(int i=0;i<pre.size();i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<pre.size();i++){
        cout<<in[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<pre.size();i++){
        cout<<post[i]<<" ";
    }
    
}
node* newNode(int data){
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
int main(){
    node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(5);
    root->left->left=newNode(3);
    root->left->right=newNode(4);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    func(root);
}