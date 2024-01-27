#include <bits/stdc++.h>
using namespace std;
int main(){
    map<pair<int,int>,int>m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       int a,b;
       int cnt;
       cin>>a>>b>>cnt; 
       
       m[{a,b}]=cnt;

   }
   for(auto &pr:m){
       cout<<"Key Values\n";
     cout<<pr.first.first<<" "<<pr.first.second<<endl;

     cout<<"Value correspoding to that key\n";
     cout<<pr.second<<endl;
   }
    
}