class Solution {
public:
    int m,n;
    
    int solve(vector<vector<int>> &dp,vector<vector<int>>& grid, int r, int p,  vector<vector<int>>& moveCost){
        if(r==m) return 0;
        if(dp[r][p]!=-1) return dp[r][p];

        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            int d=solve(dp,grid,r+1,j,moveCost);
            int cost=0;
            if(p!=n){
                int temp=grid[r-1][p];
                cost+=moveCost[temp][j];
            }
            mini=min(mini,grid[r][j]+d+cost);
        }
        return dp[r][p] =mini;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m=grid.size();
        n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n+1,-1));
        return solve(dp,grid,0,n,moveCost);
    }
};