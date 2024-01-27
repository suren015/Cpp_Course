#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<int>BFS(int V,vector<int>adj[])
{
    vector<int>vis(V+1,0);
    queue<int>q;
    vector<int>bfs;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int node = q.front();
        bfs.push_back(node);
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void DFS(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfs)
{
    vis[node]=1;
    dfs.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            DFS(it,adj,vis,dfs);
        }
    }
}





void solve(){
    


}

signed main(){
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}