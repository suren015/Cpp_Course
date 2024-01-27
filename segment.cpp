#include <bits/stdc++.h>
using namespace std;
int a[100005],seg[4*100005];

void build(int idx,int low,int high){
    if(low==high){
        seg[idx] = a[low];
        return;
    }
    int mid = low + (high-low)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);

    //backtracking
    seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);
}

int query(int idx,int low,int high,int l,int r){
    //Chcking three condition::
    //(1) low and high of seg tree completely inside in our query i.e. l and r
    //(2) Doesn't overlap 
    //(3) overlapping

    if(low>=l && high<=r){
        return seg[idx];
    }

    if(high<l || low>r){
       return INT_MIN; 
    }

    int mid = low + (high-low)/2;
    int left = query(2*idx+1,low,mid,l,r);
    int right = query(2*idx+2,mid+1,high,l,r);
    return max(left,right);
}

void pointupdate(int idx,int low,int high,int node,int val){
    if(low==high){
        seg[idx]+=val;
        return;
    }

    int mid = low + (high-low)/2;
    if(node>=low && node<=mid){
        pointupdate(2*idx+1,low,mid,node,val);
    }else{
        pointupdate(2*idx+2,low,high,node,val);
    }

    //backtracking
    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(0,0,n-1);

    //query for maximum in range
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
    return 0;
}