/* Given N strings and Q queries. In each query you
are given a string , print yes if string is present 
else print no.  */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;cin>>n;
        int flag=0;
        unordered_set<string>s;
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            s.insert(str);
        }
  
        string str1;
        cin>>str1;
        for(auto &it : s){
            if( (it)==str1){
                cout<<"yess"<<endl;
                flag=5;
                break;
            }
            }
            if(flag==0){
               cout<<"no"<<endl;
            }
           
         }
    }
