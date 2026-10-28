class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir={{-1,1},{0,1},{1,1}};

    bool isValid(int i, int j){
        return (i>=0 && j>=0 && i<m && j<n);
    }

    int solve(vector<vector<int>>& dp,vector<vector<int>>& grid, int i, int j){
        int maxMove=0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        for(int d=0;d<3;d++){
            int r=i+dir[d].first;
            int c=j+dir[d].second;
            if(isValid(r,c) && grid[i][j]<grid[r][c]){
                int moves=solve(dp,grid,r,c);
                maxMove=max(maxMove,1+moves);
            }
        }

        return dp[i][j]=maxMove;
    }

    int maxMoves(vector<vector<int>>& grid){
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            ans=max(ans,solve(dp,grid,i,0));
        }
        return ans;
    }
};