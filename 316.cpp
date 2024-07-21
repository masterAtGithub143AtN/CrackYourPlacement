#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        stack<char> ans;
        int i=0;
        int arr[26]={0};
        while(i<n){
            char c=s[i];
            while((ans.size()!=0) && ans.top()>c && arr[c-'a']==0 && mp[ans.top()]>=1){
                arr[ans.top()-'a']=0;
                ans.pop();
            }
            mp[c]--;
            if(arr[c-'a']==0){
                ans.push(c);
                arr[c-'a']=1;
            }
            
            i++;
        }
        string a="";
        while(!ans.empty()){
            a.push_back(ans.top());
            ans.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};