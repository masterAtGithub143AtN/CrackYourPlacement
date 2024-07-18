#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(int open,int close,int n,vector<string>&ans,string s){
        if(open>=n && close>=n && open+close>=2*n){
            ans.push_back(s);
            return ;
        }
        if(open>n){
            return ;
        }
        if(close>n){
            return ;
        }
        // cout<<s<<" "<<open<<" "<<close<<endl;
        if(open>close){
            find(open,close+1,n,ans,s+')');
            find(open+1,close,n,ans,s+'(');
        }
        else{
            find(open+1,close,n,ans,s+'(');
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find(0,0,n,ans,"");
        return ans;
    }
};