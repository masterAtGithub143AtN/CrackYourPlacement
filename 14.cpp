#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        string temp="";
        temp=strs[0];
        int n=strs.size();
        for(int i=1;i<n;i++){
            ans="";
            int j=0;
            int m=min(temp.size(),strs[i].size());
            while(j<m && strs[i][j]==temp[j]){
                ans.push_back(temp[j]);
                j++;
            }
            temp=ans;
        }
        return temp;
    }
};