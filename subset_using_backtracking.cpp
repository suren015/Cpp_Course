#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>subsets;

void generate(vector<int>&subset,int i,vector<int>&nums){
    //base condition
    if(i==nums.size()){
        subsets.push_back(subset);
        return;
    }

    //ith element not in the subset
    generate(subset,i+1,nums);

    //ith element in the subset
    subset.push_back(nums[i]);
    generate(subset,i+1,nums);
    subset.pop_back();
}
int main(){
    int n;cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>empty;
    generate(empty,0,nums);

    for(auto it:subsets){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}