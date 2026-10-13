class Solution {
public:
    int solve(vector<vector<int>>&dp ,int m, int n, vector<vector<int>>& obstacleGrid){
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return 1;
        if(obstacleGrid[m][n]==1) return 0;

        if(dp[m][n]!=-1) return dp[m][n];

        //up and left
        int count=0;
        count+=solve(dp,m-1,n, obstacleGrid);
        count+=solve(dp,m,n-1, obstacleGrid);
        return dp[m][n]=count;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(dp, m-1,n-1, obstacleGrid);
    }
};