#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int,string>m;
    m[1]="abc";  // O(log(n))
    m[5]="cdc";
    m[3]="acd";
    m.insert({4,"afg"});
    m[6];
    m[5]="cde";
    

    map<int,string>::iterator it=m.begin();
    for(it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    for(auto &it : m){
        cout<<(it).first /* O(log(n)) */<<" "<<(it).second /* O(log(n)) */<<endl; 
    }

     
 }