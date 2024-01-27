#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;

int vis[N],vis1[N];
vector<int>adj[N];

void dfs_pre(int node){
    //preorder
    vis[node]=1;
    cout<<node<<" ";

    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(vis[*it]==0){
            dfs_pre(*it);
        }
    }
}
void dfs_post(int node){
    //postorder
    vis1[node]=1;
   

    vector<int>::iterator it1;
    for(it1=adj[node].begin();it1!=adj[node].end();it1++){
        if(vis1[*it1]==0){
            dfs_post(*it1);
        }
    }
     cout<<node<<" ";
}

int main(){
    for(int i=0;i<N;i++){
        vis[i]=0;
        vis1[i]=0;
    }
    int n,e;
    cin>>n>>e;
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs_pre(1);
    cout<<endl;
    dfs_post(1); 
     
}