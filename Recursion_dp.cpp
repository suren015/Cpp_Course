#include <bits/stdc++.h>
using namespace std;
#define int long long

int fibo(int n,vector<int>&dp)
{
    if(n<=1){
        return n;
    }

    //Checking
    if(dp[n]!=-1){
        return dp[n];
    } 

    //Storing
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}

bool subset_sum_equal_to_k(int i,int target,vector<int>&a,vector<vector<int>>&dp)
{
    if(target==0){
        return true;
    }
    if(i==0){
        return a[i]==target;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    //take condition
    bool take=false;
    if(a[i]<=target){
        take=subset_sum_equal_to_k(i-1,target-a[i],a,dp);
    }
    //not take condition
    bool not_take=subset_sum_equal_to_k(i-1,target,a,dp);

    return dp[i][target]=take+not_take;
}

bool partition_equal_subset_sum(int n,vector<int>&a)
{
    int sum=0;
    for(auto it: a){
        sum+=it;
    }
    if(sum%2!=0){
        return false;
    }
    vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
    return subset_sum_equal_to_k(n-1,sum/2,a,dp);
}

int partition_a_set_into_two_subset_with_min_abs_diff(int n, vector<int>&a)
{
    int sum=0;
    for(auto x: a){
        sum+=x;
    }
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    int mini=INT_MAX;
    for(int i=0;i<=sum;i++){
        bool x = subset_sum_equal_to_k(n-1,i,a,dp);
        if(x==true){
            int s1 = i;
            int s2 = sum-i;
            mini=min(mini,abs(s1-s2));
        }
    }
    return mini;
}

int cnt_subset_with_sum_k(int i,int sum,vector<int>&v,vector<vector<int>>&dp)
{
    if(i==0){
        if(sum==0 && v[i]==0){
            return 2;
        }
        if(sum==0 || v[i]==sum){
            return 1;
        }
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }

    //Not pick 
    int np = cnt_subset_with_sum_k(i-1,sum,v,dp);

    //pick
    int p = 0;
    if(v[i]<=sum){
        p = cnt_subset_with_sum_k(i-1,sum-v[i],v,dp);
    }

    return dp[i][sum] = p + np;
}

int cnt_partition_with_given_diff(int d,vector<int>&v)
{
    int n=v.size();
    int totSum=0;
    for(auto &it : v){
        totSum+=it;
    }
    if(totSum-d<0 || (totSum-d)%2){
        return 0;
    }
    vector<vector<int>>dp(n,vector<int>((totSum-d)/2 +1,-1));
    return cnt_subset_with_sum_k(n-1,(totSum-d)/2,v,dp);
}

int knapsack(int i,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp)
{
    //base case
    if(i==0){
        if(wt[i]<=W){
            return val[i];
        }
        return 0;
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }

    //not take case
    int nt = 0 + knapsack(i-1,W,wt,val,dp);

    //take case
    int t = INT_MIN;
    if(wt[i]<=W){
        t = val[i] + knapsack(i-1,W-wt[i],wt,val,dp);
    }

    return dp[i][W] = max(t,nt);
}

int target_sum(int n,int target,vector<int>&v)
{
    int totsum=0;
    for(auto &it: v){
        totsum+=it;
    }
    if(totsum-target<0 || (totsum-target)%2){
        return 0;
    }
    vector<vector<int>>dp(n,vector<int>((totsum-target)/2 + 1,-1));
    return cnt_subset_with_sum_k(n-1,(totsum-target)/2,v,dp);
}

int unbounded_knapsack(int i,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp)         //Infinite supply of any item
{
    //base case
    if(i==0){
        return (W/wt[0])*val[0];
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    //not take
    int nt = 0 + unbounded_knapsack(i-1,W,wt,val,dp);

    //take
    int t = INT_MIN;
    if(wt[i]<=W){
        t = val[i] + unbounded_knapsack(i,W-wt[i],wt,val,dp);
    }

    return dp[i][W] = max(t,nt);
}

void solve(){

    /*--------------------Fibonacci dp----------------------------------*/

    // int n;
    // cin>>n;
    // vector<int>dp(n+1,-1);
    // cout<<fibo(n,dp)<<endl;

    /*--------------------Subset sum equal to k or not (dp)--------------------*/

    // int n,k;
    // cin>>n>>k;
    // vector<int>a(n);
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // cout<<subset_sum_equal_to_k(n-1,k,a,dp)<<endl;

    /*--------------------Partition equal subset sum or not (dp)----------------------*/

    // int n;
    // cin>>n;
    // vector<int>a(n);
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // cout<<partition_equal_subset_sum(n,a)<<endl;

    /*-------------------Partition a set into two subset with minimum abs diff------------------------*/

    // int n;
    // cin>>n;
    // vector<int>a(n);
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // cout<<partition_a_set_into_two_subset_with_min_abs_diff(n,a)<<endl;

    /*-------------------Count the subset with sum k-------------------------------------------------------*/

    // int n,k;
    // cin>>n>>k;
    // vector<int>v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // cout<<cnt_subset_with_sum_k(n-1,k,v,dp)<<endl;;

    /*-------------------Count the total no. of partition with given Difference----------------------------------*/

    // int n,diff;
    // cin>>n>>diff;
    // vector<int>v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // cout<<cnt_partition_with_given_diff(diff,v)<<endl;

    /*--------------------Knapsack Problem------------------------------------------------------------------------*/

    // int n,W;
    // cin>>n>>W;
    // vector<int>wt(n);
    // vector<int>val(n);
    // for(int i=0;i<n;i++){
    //     cin>>wt[i];
    // }
    // for(int i=0;i<n;i++){
    //     cin>>val[i];
    // }
    // vector<vector<int>>dp(n,vector<int>((W+1),-1));
    // cout<<knapsack(n-1,W,wt,val,dp)<<endl;

    /*--------------------Target Sum------------------------------------------------------------------------------------*/

    // int n,target;
    // cin>>n>>target;
    // vector<int>v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // cout<<target_sum(n,target,v)<<endl;

    /*--------------------Unbounded Knapsack Problem-------------------------------------------------------------------------*/

    // int n,W;
    // cin>>n>>W;
    // vector<int>wt(n),val(n);
    // for(int i=0;i<n;i++){
    //     cin>>wt[i];
    // }
    // for(int j=0;j<n;j++){
    //     cin>>val[j];
    // }
    // vector<vector<int>>dp(n,vector<int>(W+1,-1));
    // cout<<unbounded_knapsack(n-1,W,wt,val,dp)<<endl;

    /*----------------------------------*/
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}