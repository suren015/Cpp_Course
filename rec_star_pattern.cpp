#include<bits/stdc++.h>
using namespace std;
void pattern(int x,int y,int n){
    if(x==n+1){
        return;
    }
    for(int i=0;i<x;i++){
       cout<<'*';
    }
    for(int i=0;i<y;i++){
       cout<<" ";
    }
    cout<<endl;
    pattern(x+1,y-1,n);
}
int main(){
    int n;
    cin>>n;
    pattern(1,n-1,n);
}