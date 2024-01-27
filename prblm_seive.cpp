#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    vector<int>is_prime(51,0);
    is_prime[0]=1;
    is_prime[1]=1;
    for(int i=2;i<51;++i){
        if(is_prime[i]==0){
            for(int j=2*i;j<51;j+=i){
                is_prime[j]=1;
            }
        }
    }
    for(int i=0;i<51;i++){
        cout<<is_prime[i]<<" ";
    }
}