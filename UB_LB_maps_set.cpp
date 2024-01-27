#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    // set<int>s;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     s.insert(x);
    // }
    // iss case me time complexity O(log(n)) naa hokr O(n) h
    /*
    auto it=lower_bound(s.begin(),s.end(),5);
    if(it==s.end()){
        cout<<"not found"<<endl;
        return 0;
    }
    cout<<(*it)<<endl;
    */
    // for(int i=0;i<n;i++){
    //     auto it=s.lower_bound(5);
    //     cout<<(*it)<<endl;
    //     return 0;
    // }
    
    map<int,int>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m[i]=x;
    }
    
    for(int i=0;i<n;i++){
        auto it=m.lower_bound(5);
        if(it==m.end()){
            cout<<"Not Found"<<endl;
            return 0;
        }
       
       cout<<(*it).first<<" "<<(*it).second<<endl;

    }
}



