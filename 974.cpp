#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> s;
        s[0]=0;
        int ans=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int reminder=sum%k;
            if(reminder<0){
                reminder+=k;
            }
            if(s.find(reminder)==s.end()){
                s[reminder]=0;
            }
            else{
                s[reminder]=s[reminder]+1;
                ans+=s[reminder];
            }
        }
        return ans;
    }
};