#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<n && s[i]==' '){
            i++;
        }
        while(j>=i && s[j]==' '){
            j--;
        }
        string ans="";
        // cout<<i<<endl;
        while(j>=i){
            int k=j;
            while(k>=i && s[k]!=' '){
                k--;
            }
            int l=k;
            k++;
            while(k<=j){
                ans.push_back(s[k]);
                k++;
            }
            j=l;
            if(l>=i){
                ans.push_back(' ');
            }
            while(j>=i && s[j]==' '){
                j--;
            }

        }
        return ans;
    }
};