#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* newnode(int key){
    node* temp=new node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}
node* insert(node* root,int elem){
    if(root==NULL){
        node* p=new node;
        p->data=elem;
        p->left=p->right=NULL;
        return p;
    }
    if(root->data>elem){
        root->left=insert(root->left,elem);
    }else{
        root->right=insert(root->right,elem);
    }
    return root;
}
node* minvalnode(node* root){
    node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* Delete(node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=Delete(root->left,key);
    }else if(key>root->right){
        root->right=Delete(root->right,key);
    }else{
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }else if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }else{
            node* temp=minvalnode(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->key);
        }
    }
    return root;
}
node* Rsearch(node* root,int elem){
    if(root==NULL){
        cout<<"Not Found"<<endl;
        return root;
    }
    if(elem==root->data){
        cout<<"found"<<endl;
        return root;
    }else if(elem<root->data){
        root->left=Rsearch(root->left,elem);
        
    }else{
        root->left=Rsearch(root->right,elem);
    }
    return root;
}
int findMax(node* root){
    node* curr=root;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    return curr->data;
}
int findMin(node* root){
    node* curr=root;
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr->data;
}
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
void levelorder(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
        cout<<curr->data<<" ";
    }
}
void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node* root=newnode(a[0]);
    
    for(int i=1;i<n;i++){
        insert(root,a[i]);
    }
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    // Rsearch(root,7);
    // cout<<endl;
    // root=Delete(root,7);
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    int max=findMax(root);
    cout<<max<<endl;
    int min=findMin(root);
    cout<<min<<endl;
    cout<<check(root)<<endl;
    levelorder(root);
   
}