#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int pre[n+1];
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=a[i]^pre[i-1];
        }

        int l,r;
        cin>>l>>r;
        int ans=pre[r]^pre[l-1];
        cout<<ans<<endl;

    }
    
}