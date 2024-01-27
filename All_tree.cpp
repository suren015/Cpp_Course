#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

//for res height 
int maxDepth(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return 1+max(lh,rh);
}

//diameter of a tree in O(n)
int height(node* root,int& maxi){
    if(root==NULL){
        return 0;
    }
    int lh1=height(root->left,maxi);
    int rh1=height(root->right,maxi);
    maxi=max(maxi,lh1+rh1);
    return 1+max(lh1,rh1);
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int maxi=0;
    height(root,maxi);
    return maxi;
}


//checking whether a balanced tree or not a balanced tree
int check(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=check(root->left);
    int rh=check(root->right);
    if(lh==-1 || rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    return 1+max(lh,rh);
}

//maximum path sum in a binary tree
int solve(node* root,int& res){
    if(root==NULL){
        return 0;
    }
    int l=solve(root->left,res);
    int r=solve(root->right,res);
    int a1=max(max(l,r)+root->data,root->data);  //if lh2 is positive but rh2 is negative
    int a2=max(a1,l+r+root->data);
    res=max(res,a2);
    return a1;
}
int max_path_sum(node* root){
   
    int res=0;
    solve(root,res);
    return res;

}


node* newNode(int data){
    node* temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main(){
    node* root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(4);
   root->left->left=newNode(3);
   root->left->right=newNode(9);
   root->right->left=newNode(5);
   root->right->right=newNode(6);
   root->right->right->right=newNode(7);
   root->right->right->right->right=newNode(10);
   
   cout<<check(root)<<endl;
   cout<<endl;
   cout<<diameter(root);
   cout<<endl;
   cout<<max_path_sum(root);
   cout<<endl;
   return 0;
}