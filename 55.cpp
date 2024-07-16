#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return true;
        }
        int i=n-2;
        while(i>=0){
            if(nums[i]!=0){
                i--;
                continue;
            }
            int cnt=1;
            i--;
            while(i>=0 && nums[i]<cnt){
                i--;
                cnt++;
            }
            if(i<0){
                return false;
            }
        }
        return true;
    }
};