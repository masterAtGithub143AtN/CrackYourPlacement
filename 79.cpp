#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find(int i,int j,int n,int m,vector<vector<char>>& board,int k,int l,string word){
        // cout<<k<<" ";
        if(k>=l){
            return true;
        }
        if(i<0 || i>=n || j>=m || j<0 || board[i][j]=='.'){
            return false;
        }
        bool ans=false;
        if(board[i][j]==word[k]){
            board[i][j]='.';
            //up
            if(find(i-1,j,n,m,board,k+1,l,word)==true){
                return true;
            }
            //down
            if(find(i+1,j,n,m,board,k+1,l,word)==true){
                return true;
            }
            //left
            if(find(i,j-1,n,m,board,k+1,l,word)==true){
                return true;
            }
            //right
            if(find(i,j+1,n,m,board,k+1,l,word)==true){
                return true;
            }
            board[i][j]=word[k];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                // cout<<i<<" "<<j<<endl;
                if(find(i,j,board.size(),board[i].size(),board,0,word.size(),word)==true){
                    return true;
                }
                // cout<<endl;
            }
        }
        return false ;
    }
};