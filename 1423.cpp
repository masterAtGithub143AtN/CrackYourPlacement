#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int i,int j,vector<int> a,int k,int cnt,vector<int> &dp){
        if( cnt>=k){
            return 0;
        }
        int ans=0;
        ans=max(find(i+1,j,a,k,cnt+1,dp)+a[i],find(i,j-1,a,k,cnt+1,dp)+a[j]);
        return ans;
    }
    int maxScore(vector<int>& cardPoints, int k) {

        int ans=0;

        int sum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        ans=max(ans,sum);
        int i=k-1;
        int j=n-1;
        while(i>=0){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            i--;
            j--;
            ans=max(ans,sum);
        }
        return ans;



        vector<int> dp(cardPoints.size()+1,-1);
        return find(0,cardPoints.size()-1,cardPoints,k,0,dp);
    }
};