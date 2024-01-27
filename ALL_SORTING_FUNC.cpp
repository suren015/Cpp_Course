#include <bits/stdc++.h>
using namespace std;
void display(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

//Bubble Sort Algorithm
void bubble_sort(int a[],int n){
    int flag;
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if(flag==0){   //check whether array already sorted
            break;
        }
    }
}    

//Insertion Sort Algorithm
void insert_sort(int a[],int n){
    //assume 1st element of array is sorted, move to next element
    for(int i=1;i<n;i++){
        int x=a[i];
        int j=i-1;
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}


// Merge Algorithm
void Merge(int a[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int b[h+1];
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=h){
        b[k++]=a[j++];
    }
    for(int i=l;i<=h;i++){
        a[i]=b[i];
    }
}

//Iterative Merge Sort Algorithm
void ImergeSort(int a[],int n){
    int p;
    for(p=2;p<=n;p=p*2){
        for(int i=0;i+p-1<n;i=i+p){
            int l=i;
            int h=i+p-1;
            int mid=(h+l)/2;
            Merge(a,l,mid,h);
        }
    }
    if(p/2<n){
        Merge(a,0,p/2 - 1,n-1);
    }
}

//Recursive Merge Sort Algorithm
void RmergeSort(int a[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        RmergeSort(a,l,mid);
        RmergeSort(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}

//Count Sort Algorithm
void count_sort(int a[],int n){
    int m=*max_element(a,a+n);
    int c[m+1]={0};
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    int i=0,k=0;
    while(i<=m){
        if(c[i]>0){
            a[k++]=i;
            c[i]--;
            continue;
        }
        i++;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble_sort(a,n);
    insert_sort(a,n);
    selection_sort(a,n);
    QuickSort(a,0,n-1);
    ImergeSort(a,n);
    RmergeSort(a,0,n-1);
    count_sort(a,n);
    display(a,n);
}