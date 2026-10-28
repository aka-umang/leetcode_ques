class Solution {
public:
    int m,n;
    
    int solve(vector<vector<int>>&dp,vector<vector<int>>& grid, int i, int j){
        if(dp[i][j]!=-2) return dp[i][j];

        int r= (j+1>=n || grid[i][j+1]<=grid[i][j])?-1:  solve(dp,grid,i,j+1);
        int ru= (i-1<0 || j+1>=n || grid[i-1][j+1]<=grid[i][j])?-1: solve(dp,grid,i-1,j+1);
        int rd= (i+1==m || j+1==n || grid[i+1][j+1]<=grid[i][j])?-1: solve(dp,grid,i+1,j+1);

        return dp[i][j]=1+max({r,ru,rd});
    }

    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,-2));
        for(int i=0;i<m;i++){
            ans=max(ans,solve(dp,grid,i,0));
        }
        return ans;
    }
};