#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int find(int i, int n, vector<int>& prices, int status,
             vector<vector<int>>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][status] != -1) {
            return dp[i][status];
        }
        int currProfit = INT_MIN;
        if (status == 0) {
            currProfit = max(find(i + 1, n, prices, 1, dp) - prices[i],
                             find(i + 1, n, prices, 0, dp));
        } else {
            currProfit = max(find(i + 1, n, prices, 0, dp) + prices[i],
                             find(i + 1, n, prices, 1, dp));
        }
        return dp[i][status] = currProfit;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        // dp[prices.size()][0] = dp[prices.size()][1] = 0;
        // for (int i = prices.size() - 1; i >= 0; i--) {
        //     for (int status = 0; status <= 1; status++) {
        //         int currProfit = 0;
        //         if (status == 0) {
        //             currProfit = max(dp[i+1][1]- prices[i],dp[i+1][0]);
        //         } else {
        //             currProfit = max(dp[i+1][0] + prices[i],
        //                              dp[i+1][1]);
        //         }
        //        dp[i][status] = currProfit;
        //     }
        // }
        // return dp[0][0];

        vector<int> next(2,0),curr(2,0);
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int status = 0; status <= 1; status++) {
                int currProfit = 0;
                if (status == 0) {
                    currProfit = max(next[1]- prices[i],next[0]);
                } else {
                    currProfit = max(next[0] + prices[i],
                                     next[1]);
                }
               curr[status] = currProfit;
            }
            next=curr;
        }
        return next[0];

        // return find(0, prices.size(), prices, 0, dp);
    }
};