// store only unique element and in sorted order
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    
     set<string>s;
     for (int i=0;i<n;i++){
         string x;
         cin>>x;
         s.insert(x);
     }
    set<string>::iterator it=s.begin();
    for(it=s.begin();it!=s.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
    for(auto &it : s){
        cout<<(it)<<" ";
    }
}