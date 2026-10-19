class Solution {
public:
    int m,n;

    int solve(vector<vector<int>>& dp,vector<vector<int>>& grid, int i, int j){
        if(i==m || j==n) return INT_MAX;

        if(i==m-1 && j==n-1){
            return grid[i][j];
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int down=solve(dp,grid,i+1,j);
        int right=solve(dp,grid,i,j+1);

        int mini=min(down,right);
        
        if(mini!=INT_MAX)  mini+=grid[i][j];

        return dp[i][j]=mini;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(dp,grid,0,0);
    }
};