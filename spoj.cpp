#include <bits/stdc++.h>
using namespace std;
#define int long long
const int dx[] = {-2,-1,1,2,2,1,-1,-2};
const int dy[] = {1,2,2,1,-1,-2,-2,-1};
void fun(int row,int col,int grid[8][8],vector<pair<int,int>>&ans,int cnt){
    ans.push_back({row,col});
    if(cnt==63){
        return;
    }
    for(int i=0;i<8;i++){
        int drow = row+dx[i];
        int dcol = col+dy[i];
        if(drow>=0 && drow<8 && dcol>=0 && dcol<8 && grid[drow][dcol]==cnt+1){
            fun(drow,dcol,grid,ans,cnt+1);
        }
    }
}
void solve(){
    int grid[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>grid[i][j];
        }
    }
    vector<pair<int,int>>ans;
    fun(0,0,grid,ans,0);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}