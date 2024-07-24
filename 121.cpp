#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int profit=INT_MIN;
        for(int i=1;i<n;i++){
            buy=min(buy,prices[i]);
            if(prices[i]>buy){
                profit=max(profit,prices[i]-buy);
            }
        }
        if(profit==INT_MIN){
            profit=0;
        }
        return profit;
    }
};