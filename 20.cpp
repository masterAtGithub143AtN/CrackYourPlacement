#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        int i=0;
        int n=s.size();
        stack<int> st;
        while(i<n){
            while(i<n && (s[i]=='(' || s[i]=='{' || s[i]=='[')){
                st.push(s[i]);
                i++;
            }
            while(i<n && (s[i]==')' || s[i]=='}' || s[i]==']')){
                if(st.empty()){
                    return false;
                }
                if(s[i]==')'){
                    if(st.top()!='('){
                        return false;
                    }
                }
                if(s[i]=='}'){
                    if(st.top()!='{'){
                        return false;
                    }
                }
                if(s[i]==']'){
                    if(st.top()!='['){
                        return false;
                    }
                }
                i++;
                st.pop();
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};