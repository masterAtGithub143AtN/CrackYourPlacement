#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while((!s.empty()) && heights[s.top()]>=heights[i]) s.pop();
            if(s.size()==0){
                left[i]=0;
            }
            else{
                left[i]=s.top()+1;
            }
            s.push(i);
        }
        stack<int> s1;
        for(int i=n-1;i>=0;i--){
            while((!s1.empty()) && heights[s1.top()]>=heights[i]) s1.pop();
            if(s1.size()==0){
                right[i]=n-1;
            }
            else{
                right[i]=s1.top()-1;
            }
            s1.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,(heights[i]*(right[i]-left[i]+1)));
        }
        return ans;
    }

};