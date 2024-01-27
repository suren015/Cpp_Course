#include <bits/stdc++.h>
using namespace std;


void insert(int hash[],int key){
    int value=key;
    key=key%10;
    if(hash[key]==0){
      hash[key]=value;
    }else{
        while(hash[key]!=0){
            key++;
            key=key%10;
        }
        hash[key]=value;
    }
}
void print(int hash[],int n){
    for(int i=0;i<n;i++){
        cout<<hash[i]<<" ";
    }
    cout<<endl;
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