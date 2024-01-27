#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1]={0};
    for(int i=0;i<=n;i++){
        if(i==0 || i==1){
            a[i] = 1;
        }else{
            if(a[i]!=1){
                for(int j=2;j<=n/i;j++){
                    a[i*j] = 1;

                }
            }
        }
        
    }
    
        for(int i=0;i<=n;i++){
            cout<<a[i]<<" ";
        }
}