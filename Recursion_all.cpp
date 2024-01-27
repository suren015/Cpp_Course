#include <bits/stdc++.h>
using namespace std;
#define int long long

void combination_sumII(int idx,int arr[],int n,int target,vector<int>&v) //Sorted Array and duplicate combination not available
{    
    if(target==0){
        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
        
    
    for(int i=idx;i<n;i++){
        if(i>idx && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        if(arr[i]<=target){
            v.push_back(arr[i]);
            combination_sumII(i+1,arr,n,target-arr[i],v);
            v.pop_back();
        }
    }
}

void combination_sum(int idx,int arr[],int n,vector<int>&ans,int target)    //an element of an array can be used more than one time
{
    if(idx==n){
        if(target==0){
            for(auto it: ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(target>=arr[idx]){
        ans.push_back(arr[idx]);
        combination_sum(idx,arr,n,ans,target-arr[idx]);
        ans.pop_back();
    }

    combination_sum(idx+1,arr,n,ans,target);
}

void Printing_subseq_whose_sum_is_k(int idx,int sum,int arr[],int n,vector<int>&ans,int k)
{
    if(idx==n){
        if(sum==k){
            for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<endl;
        } 
        return;
    }

    ans.push_back(arr[idx]);
    sum+=arr[idx];
    Printing_subseq_whose_sum_is_k(idx+1,sum,arr,n,ans,k);
    ans.pop_back();
    sum-=arr[idx];
    Printing_subseq_whose_sum_is_k(idx+1,sum,arr,n,ans,k);
}

void Print_all_subseq(int idx,int arr[],int n,vector<int>&ans)
{
    if(idx>=n){
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    //taking this index
    ans.push_back(arr[idx]);
    Print_all_subseq(idx+1,arr,n,ans);
    ans.pop_back();

    //Not taking that index
    Print_all_subseq(idx+1,arr,n,ans);
}

void subseq_by_power_set(int arr[],int n)
{
    int k=(1<<n);

    for(int i=0;i<k;i++){
        vector<int>ans;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                ans.push_back(arr[j]);
            }
        }
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int count_the_subseq_whose_sum_is_k(int idx,int arr[],int n,int k,int sum)
{
    //Base cond.
    if(idx==n){
        if(sum==k){
            return 1;
        }else{
            return 0;
        }
    }
    
    //take 
    sum+=arr[idx];
    int l=count_the_subseq_whose_sum_is_k(idx+1,arr,n,k,sum);
    sum-=arr[idx];

    //not take
    int r=count_the_subseq_whose_sum_is_k(idx+1,arr, n, k, sum);

    return l+r;
}

void subset_sum(int idx,int arr[],int n,int sum,vector<int>&v)
{

    if(idx==n){
        v.push_back(sum);
        return;
    }

    subset_sum(idx+1,arr,n,sum+arr[idx],v);

    subset_sum(idx+1,arr,n,sum,v);
}

void subsets(int idx,int arr[],int n,vector<int>&ans)
{
    
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
      
    for(int i=idx;i<n;i++){
        if(i>idx && arr[i]==arr[i-1]){
            continue;
        }
        ans.push_back(arr[i]);
        subsets(i+1,arr,n,ans);
        ans.pop_back();
    }
}

void permutation(int arr[],int n,vector<int>&v,map<int,int>&mp)
{
    if(v.size()==n){
        for(auto it: v){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(mp[arr[i]]==0){
            mp[arr[i]]=1;
            v.push_back(arr[i]);
            perm(arr,n,v,mp);
            mp[arr[i]]=0;
            v.pop_back();
        }
        
    }
}

void permutation_swap(int idx,int arr[],int n)
{
    if(idx==n){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=idx;i<n;i++){
        swap(arr[i],arr[idx]);
        permutation_swap(idx+1,arr,n);
        swap(arr[i],arr[idx]);
    }
}

int32_t main()
{
    int n,k;
    cin>>n>>k;
    // vector<int>ans;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    // Printing_subseq_whose_sum_is_k(0,sum,a,n,ans,k);
    // Print_all_subseq(0,a,n,ans);
    // subseq_by_power_set(a,n);
    // cout<<count_the_subseq_whose_sum_is_k(0,a,n,k,0);

}