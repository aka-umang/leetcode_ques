class Solution {
public:
    int solve(int M, int N, vector<vector<int>>& obstacleGrid){
        vector<vector<int>>dp(M+1,vector<int>(N+1,-1));
        
        for(int m=0;m<=M;++m){
            for(int n=0;n<=N;++n){
                if(m==0 && n==0){
                    dp[0][0]=1;
                    continue;
                }
                if(obstacleGrid[m][n]==1){
                    dp[m][n]=0;
                    continue;
                }
                int count=0;
                if(m-1>=0) count+=dp[m-1][n]; //up
                if(n-1>=0) count+=dp[m][n-1]; //left
                dp[m][n]=count;
            }
        }
        return dp[M][N];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        return solve(m-1,n-1, obstacleGrid);
    }
};