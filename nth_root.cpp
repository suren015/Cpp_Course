#include <bits/stdc++.h>
using namespace std;
const double eps=1e-6;  // nth root is of how much decimal 0.000001
double multiply(double mid,int n){
    double ans=1;
    for(int i=0;i<n;i++){
        ans*=mid;
    }
    return ans;
}

int main(){
    double x;
    int n;
    cin>>x>>n;
    double low=1,high=x;
    double mid;
    while(high-low>eps){
        mid=(high+low)/2;
        if(multiply(mid,n)<x){
            low=mid;
        }else{
            high=mid;
        }
    }
    // Time Complexity= n*(log(x*10^d))  d==upto decimal no.
    cout<<low<<endl;  // low ki jgh high bhi print kr skte h same aayegi value
    cout<<pow(x,1.0/n)<<endl;
}