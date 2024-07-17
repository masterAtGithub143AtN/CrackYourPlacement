#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pr;
        int n=points.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            while(!pr.empty() && points[i][0]-pr.top().second>k){
                pr.pop();
            }
            if(!pr.empty()){
                ans=max(ans,points[i][0]+points[i][1]+pr.top().first);
            }
            pr.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }
};