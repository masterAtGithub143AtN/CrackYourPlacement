#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(int i,int n,vector<int> &nums,set<vector<int>> &mp){
        if(i>=n){
            mp.insert(nums);
            return ;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            find(i+1,n,nums,mp);
            swap(nums[i],nums[j]);
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        set<vector<int>> mp;
        find(0,nums.size(),nums,mp);
        vector<vector<int>> ans;
        for(auto it : mp){
            ans.push_back(it);
        }
        return ans;
        
    }
};