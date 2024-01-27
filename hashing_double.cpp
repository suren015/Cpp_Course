#include<bits/stdc++.h>
using namespace std;


void insert(int hash[],int key){
    int value=key;
    key=key%10;
    if(hash[key]==0){
        hash[key]=value;
    }else{
        int i=0;
        int ans=key;
        while(hash[ans]!=0){
            ans=(key+i*(7-(value%7)))%10;
            i++;
        }
        hash[ans]=value;
    }
}
void print(int hash[],int n){
    for(int i=0;i<n;i++){
        cout<<hash[i]<<" ";
    }
}
int main(){
    int hash[10]={0};
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        insert(hash,a[i]);
    }
    print(hash,10);
}