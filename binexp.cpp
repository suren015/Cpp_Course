#include <bits/stdc++.h>
using namespace std;
const int m=1e9+7;
int binexp(int a,int b,int m){
    if(b==0){
        return 1;
    }
    int temp=binexp(a,b/2,m);
    if(b%2==0){
        return (temp*temp)%m;
    }else{
        return (((temp*temp)%m)*a)%m;
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<binexp(a,b,m);
}