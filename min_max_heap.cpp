
#include <iostream>
using namespace std;
void max_heap(int a[],int n){
    int temp;
    int i=n;
    temp=a[i];
    while(i>1 && temp>a[i/2]){
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
void min_heap(int a[],int n){
    int temp;
    int i=n;
    temp=a[i];
    while(i>1 && temp<a[i/2]){
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

int main(){
    int a[]={0,4,99,35,43,85,65};
    for(int i=2;i<=6;i++){
        min_heap(a,i);
    }
    for(int i=1;i<=6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int b[]={0,4,99,35,43,85,65};
    for(int i=2;i<=6;i++){
        max_heap(b,i);
    }
    for(int i=1;i<=6;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
}