#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int>st;
    for(int i=0;i<n;i++){
        
        while(!st.empty() && st.top()<a[i]){
            cout<<st.top()<<"--"<<a[i]<<endl;
             st.pop();
        }
        st.push(a[i]);
    }
     int next=-1;
    
    while(!st.empty()){
          cout<<st.top()<<"--"<<next<<endl;
          st.pop();
    }
}