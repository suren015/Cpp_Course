//Sorting of pairs in increasing order but when first element p[i] equal to first element of  
//p[i+1] then second element sort in decreasing order using cmp function

#include <bits/stdc++.h>
using namespace std;
int cmp(pair<int,int>a,pair<int,int>b){
    if(a.first != b.first){
        return a.first<b.first;
    }else{
        return a.second>b.second;
    }
}
int main(){
    int n;
    cin>>n;
    pair<int,int>p[n];
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p[i]={x,y};
        
    }
     sort(p,p+n,cmp);
     for(int i=0;i<n;i++){
         cout<<p[i].first<<" "<<p[i].second<<endl;
     }
}