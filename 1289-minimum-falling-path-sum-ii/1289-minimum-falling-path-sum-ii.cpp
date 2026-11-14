class Solution {
public:
    int n;

    int solve(vector<vector<int>>& grid){
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++)    dp[n][i]=0;

        for(int r=n-1;r>=0;r--){
            for(int skipCol=0; skipCol<=n;skipCol++){

                int minSum=INT_MAX;
                for(int j=0;j<n;j++){
                    if(j==skipCol) continue;
                    int downSum= dp[r+1][j];
                    minSum=min(minSum, grid[r][j]+downSum);
                }

                dp[r][skipCol]=minSum;
            }
        }
        return dp[0][n];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid[0].size();

        return solve(grid);
    }
};