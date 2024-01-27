//unordered map works on hash value
//pair data doesn't contain hash value
#include <bits/stdc++.h>
using namespace std;
void print(unordered_map<int,string>&m){
    cout<<m.size()<<endl;
    unordered_map<int,string>::iterator pr=m.begin();
    for(pr=m.begin();pr!=m.end();pr++){
        cout<<(*pr).first<<" "<<(*pr).second<<endl;
            }
}
int main(){
    // 1. inbuilt implementation
    // 2. Time complexity
    // 3. valid keys
    unordered_map<int,string>m;
    m[1]="abc";  // O(log(1))
    m[5]="cdc";
    m[3]="acd";
    m.insert({4,"afg"});
    m[6];
    m[5]="cde";
    auto it = m.find(3);  
    if(it==m.end()){
        cout<<"no value"<<endl;
    }else{
        cout<<(*it).first<<" "<<(*it).second<<endl; 
    }
    
    m.erase(it);
    print(m);
    
}