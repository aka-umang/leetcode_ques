class Solution {
public:
    int M,N,K;
    int MOD=1e9+7;

    int solve(vector<vector<vector<int>>> &dp,int m, int n,vector<vector<int>>& grid , int r){
        
        r=(r+grid[m][n])%K;
        if(m==0 && n==0)  {return r==0;}
        
        if(dp[m][n][r]!=-1) return dp[m][n][r];

        long long count=0;
        if(m>0) count=(count+solve(dp,m-1,n,grid,r))%MOD;
        if(n>0) count=(count+solve(dp,m,n-1,grid,r))%MOD;

        return dp[m][n][r]=count;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        M=grid.size();
        N=grid[0].size();
        K=k;
        
      
        vector<vector<vector<int>>> dp(
            M, vector<vector<int>>(
            N, vector<int>(K, -1)
        ));

        return solve(dp,M-1,N-1,grid,0);
    }
};