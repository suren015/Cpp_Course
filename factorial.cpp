#include<bits/stdc++.h>
using namespace std;
#define int long long
int fact(int n){
    if(n>1){
        return n*fact(n-1);
    }else{
        return 1;
    }
}
int32_t main(){
    int n;
    cin>>n;
    int ans=fact(n);
    cout<<ans<<endl;
}