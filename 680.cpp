#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool validPalindrome(string S) {
        int i=0;
        int j=S.size()-1;
        while(i<j){
            if(S[i]==S[j]){
                i++;
                j--;
            }
            else{
                bool ans=false;
                int i1=i;
                int j1=j;
                //suppose i1 deleted
                i1++;
                while(i1<j1){
                    if(S[i1]==S[j1]){
                        i1++;
                        j1--;
                    }
                    else{
                        break;
                    }
                }
                if(i1>=j1){
                    return true;
                }
                i1=i;
                j1=j;
                //suppose j deleted
                j1--;
                while(i1<j1){
                    if(S[i1]==S[j1]){
                        i1++;
                        j1--;
                    }
                    else{
                        break;
                    }
                }
                if(i1>=j1){
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};