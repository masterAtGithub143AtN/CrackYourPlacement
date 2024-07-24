#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        int cnt=1;
        int i=1;
        while(i<n){
            if(cnt==0){
                ans=nums[i];
                cnt=1;
                i++;
            }
            if(i<n &&nums[i]==ans){
                cnt++;
            }
            else if(i<n){
                cnt--;
            }
            i++;
        }
        return ans;
    }
};