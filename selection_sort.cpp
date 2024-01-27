#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
void mergeSort(int l,int r){
    if(l==r){
        return;
    }
    int mid=l+(r-l)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,mid,r);

}
void merge(int l,int mid,int r){
     int n1=mid-l+1;
     int n2=r-mid;
     int L[n1],R[n2];
     for(int i=0;i<n1;i++){
         L[i]=a[l+i];
     }
      for(int j=0;j<n2;j++){
         R[j]=a[mid+1+j];
     }
     int p,q,f;
     p=0;
     q=0;
     f=l;
     while(p<n1 && q<n2){
         if(L[p]<=R[q]){
             a[f]=L[p];
             p++;
         }else{
             a[f]=R[q];
             q++;
         }
         f++;
     }
     while(p<n1){
         a[f]=L[p];
         p++;
         f++;

     }
     while(q<n2){
         a[f]=R[q];
         q++;
         f++;
     }
}

int main(){
    int n;
    cin>>n;
    int a[n]; 
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}