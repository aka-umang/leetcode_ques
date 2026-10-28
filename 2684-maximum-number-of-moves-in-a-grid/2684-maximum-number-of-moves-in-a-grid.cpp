class Solution {
public:
    int m,n;
    
    int solve(vector<vector<int>>& grid){
        vector<vector<int>>dp(m,vector<int>(n));

        for(int j=n-1;j>=0;j--){
            for(int i=m-1;i>=0;i--){
                int r= (j+1>=n || grid[i][j+1]<=grid[i][j])?-1:  dp[i][j+1];
                int ru= (i-1<0 || j+1>=n || grid[i-1][j+1]<=grid[i][j])?-1: dp[i-1][j+1];
                int rd= (i+1==m || j+1==n || grid[i+1][j+1]<=grid[i][j])?-1: dp[i+1][j+1];

               dp[i][j]=1+max({r,ru,rd});
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
    
        return solve(grid);
    }
};