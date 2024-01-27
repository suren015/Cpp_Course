#include <bits/stdc++.h>
using namespace std;
bool pallin(int a,int b,string str){
    if(a>=b){
        return true;
    }
    if(str[a]!=str[b]){
        return false;
    }
    return pallin(a+1,b-1,str);
    
}
int main(){
    string str;
    cin>>str;
    int n=str.size();
    cout<<pallin(0,n-1,str)<<endl;
}