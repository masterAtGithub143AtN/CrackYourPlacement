#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                for(int j=0;j<n;j++){
                    if(nums[j]==target-nums[i] && i!=j){
                        return {i,j};
                    }
                }
            }
        }
    return {-1,-1};
    }
};