#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<nums.size()){
            int correctIndex=abs(nums[i])-1;
            if(correctIndex==i) i++;
            else if(abs(nums[correctIndex])==abs(nums[i])){
                if(nums[correctIndex]>0){
                     nums[correctIndex]*=-1;
                     ans.push_back(nums[i]);
                }
                i++;
            }
            else{
                swap(nums[correctIndex],nums[i]);
            }
        }
            return ans;
    }
};