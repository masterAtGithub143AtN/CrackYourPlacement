#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> ans;
        // set<pair<int,pair<int,int>>> m;
        // set<vector<int>> s;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //      unordered_set<int> mp;
        //     for(int j=i+1;j<n;j++){
        //         int req=-1*(nums[i]+nums[j]);
        //         if(mp.find(req)!=mp.end()){
        //             vector<int> arr;
        //             arr.push_back(nums[i]);
        //             arr.push_back(nums[j]);
        //             arr.push_back(req);
        //             sort(arr.begin(),arr.end());
        //             // if(m.find({arr[0],{arr[1],arr[2]}})==m.end()){
        //             //      ans.push_back(arr);
        //             //      m.insert({arr[0],{arr[1],arr[2]}});
        //             // }
        //             s.insert(arr);
        //         }
        //         mp.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans(s.begin(),s.end());
        // return ans;


        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};