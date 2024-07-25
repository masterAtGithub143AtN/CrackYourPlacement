#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=m-1;
        int reminder=0;
        string ans;
        while(i>=0 && j>=0){
            if(a[i]=='0' && b[j]=='0'){
                if(reminder==0){
                    ans.push_back('0');
                }
                else{
                    ans.push_back('1');
                    reminder=0;
                }
            }
            else if(a[i]=='0' && b[j]=='1'){
                if(reminder==0){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                }
            }
            else if(a[i]=='1' && b[j]=='0'){
                if(reminder==0){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                }
            }
            else{
                if(reminder==0){
                    ans.push_back('0');
                    reminder=1;
                }
                else{
                    ans.push_back('1');
                }
            }
            i--;
            j--;
        }
        cout<<reminder<<endl;
        while(i>=0){
            if(a[i]=='0'){
                if(reminder==0){
                    ans.push_back('0');
                }
                else{
                    ans.push_back('1');
                    reminder=0;
                }
            }
            else{
                if(reminder==0){
                    ans.push_back('1');
                    reminder=0;
                }
                else{
                    ans.push_back('0');
                }
            }
            i--;
        }
        while(j>=0){
            // cout<<j<<" "<<reminder<<" "<<b[j]<<endl;
            if(b[j]=='0'){
                if(reminder==0){
                    ans.push_back('0');
                }
                else{
                    ans.push_back('1');
                    reminder=0;
                }
            }
            else{
                if(reminder==0){
                    ans.push_back('1');
                }
                else{
                    ans.push_back('0');
                }
            }
            j--;
        }
        if(reminder!=0){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};