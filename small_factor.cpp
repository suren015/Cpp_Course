#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>small_fact(n,0);
    small_fact[0]=1;
    small_fact[1]=1;

    for(int i=2;i<n;i++){
        if(small_fact[i]==0){
            small_fact[i]=i;
            for(int j=2*i;j<n;j+=i){
                if(small_fact[j]==0){
                    small_fact[j]=i;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<small_fact[i]<<" ";
    }
}