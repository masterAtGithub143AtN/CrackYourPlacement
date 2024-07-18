#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> integer={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string ans="";
        for(int i=12;i>=0 && num>0;i--){
            while(num>=integer[i]){
                ans.append(roman[i]);
                num-=integer[i];
            }
        }
        return ans;
    }
};