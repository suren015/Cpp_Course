#include<bits/stdc++.h>
using namespace std;
bool should_i_swap(int a,int b){
    if(a>b){
        return true;
    }else{
        return false;
    }
}
int main(){
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(should_i_swap(a[i],a[j])){
    //             swap(a[i],a[j]);
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }


    int x;
    cin>>x;
    pair<int,int>p[x];
    for(int i=0;i<x;i++){
        int y,z;
        cin>>y>>z;
        p[i]=make_pair(y,z);
    }
    for(int i=0;i<x;i++){
       for(int j=i+1;j<x;j++){
           if(should_i_swap(p[i].first,p[j].first)){
               swap(p[i],p[j]);
           }else if(p[i].first==p[j].first){
               if(should_i_swap(p[i].second,p[j].second)){
                   swap(p[i],p[j]);
               }
           }
       }
    }
    for(int i=0;i<x;i++){
        cout<<p[i].first<<" "<<p[i].second<<endl;
            }
}