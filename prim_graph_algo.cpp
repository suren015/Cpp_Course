#include <bits/stdc++.h>
using nmespace std;
const int N=1e9+2;
int vis[N];
int n,e;
int vis[N];
vector<pair<int,int>>adj[N];
int cost=0;
vector<int>dist(N),parent(N);
const int INF=1e9;

void primMST(int source){
     for(int i=0;i<n;i++){
       dist[i]=INF;
     }
     set<vector<int>>s;   //{weight,vertex}
     dist[source]=0;
     s.insert({0,source});
     while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        vis[x[1]]=1;
        int x=parent[x[1]];
        int y=x[1];
        int w=x[0];
        cout<<x<<" "<<y<<" "<<w<<endl;
        cost = cost + w;
        for(auto it=adj[x[1]]){
            if(vis[it[0]]==1){
                continue;
            }else if(dist[it[0]]>it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]]=it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]]=x[1];
            }

            }
        }
     }

}
int main(){
    //initially all values of array are not visiting
    for(int i=0;i<N;i++){
        vis[i]=0;
    }
    //vertex
    cin>>n;
    //edges
    cin>>e;
    //edges connected
    int x,y,w;
    for(int i=0;i<e;i++){
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    primMST(0);
    cout<<cost<<endl;
}