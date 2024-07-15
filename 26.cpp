#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int removeDuplicates(vector<int>& nums){
        int index=0;
        if(nums.size()==1){
            return 1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[index]){
                nums[index+1]=nums[i];
                index++;
            }
        }
        return index+1;
    }
};