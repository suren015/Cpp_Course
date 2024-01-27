#include <bits/stdc++.h>
using namespace std;

void printgraph(vector<int>adj[],int n){
    for(int i=0;i<n;i++){
        cout<<"Vertex:- "<<i;
        for(auto &it:adj[i]){
            cout<<"->"<<it;
        }
        cout<<endl;
    }
    return ;
}

int main(){
    
    int n,e; //no. of vertex and edges
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    printgraph(adj,n);

}