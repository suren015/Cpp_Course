/*Given n strings and q queries.
In each query you are given a string
print frequency of that string
n<= 10^6
|s| <= 100
q<=10^6
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        unordered_map<string,int>m;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            string str;
            cin>>str;
            m[str]=m[str]+1;
        }
        for(auto &it : m){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}