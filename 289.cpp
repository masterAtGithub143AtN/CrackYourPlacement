#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c[] = {-1, 0, 1};
                int r[] = {-1, 0, 1};
                int live = 0;
                int dead = 0;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if(r[k]==0 && c[l]==0){
                            continue;
                        }
                        if (i + r[k] < n && i + r[k] >= 0 && j + c[l] < m &&
                            j + c[l] >= 0) {
                            if (board[i + r[k]][j + c[l]]%10 == 1) {
                                live++;
                            } else {
                                dead++;
                            }
                        }
                    }
                }
                // cout<<live<<" "<<dead<<endl;
                if (board[i][j] == 1) {
                    if(live<2){
                        board[i][j]=11;
                    }
                    else if(live>3){
                        board[i][j]=11;
                    }
                } else {
                    if(live==3){
                        board[i][j]=10;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==10){
                    board[i][j]=1;
                }
                if(board[i][j]==11){
                    board[i][j]=0;
                }
            }
        }
        return ;
    }
};