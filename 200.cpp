#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

 
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vist(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vist[i][j]==0 && grid[i][j]=='1'){
                    // cout<<ans<<" "<<i<<" "<<j<<endl;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vist[i][j]=1;
                    while(!q.empty()){
                        int k=q.front().first;
                        int l=q.front().second;
                        q.pop();
                        int arrR[]={0,-1,0,1};
                        int arrC[]={-1,0,1,0};
                        for(int p=0;p<4;p++){
                            if(k+arrR[p]<n && k+arrR[p]>=0 && l+arrC[p]<m && l+arrC[p]>=0 && 
                            grid[k+arrR[p]][l+arrC[p]]=='1' && vist[k+arrR[p]][l+arrC[p]]==0){
                                // cout<<"pair"<<k+arrR[p]<<" "<<l+arrC[p]<<endl;
                                q.push({k+arrR[p],l+arrC[p]});
                                vist[k+arrR[p]][l+arrC[p]]=1;
                            }
                        }
                        // cout<<"size = "<<q.size();
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};