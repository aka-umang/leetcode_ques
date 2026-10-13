class Solution {
public:
    int M,N,K;
    int MOD=1e9+7;

    int solve(int M, int N,vector<vector<int>>& grid , int r){ 
        
        vector<vector<vector<int>>> dp(
            M+1, vector<vector<int>>(
            N+1, vector<int>(K, -1)
        ));

        for(int p=0;p<K;++p){
            dp[0][0][p]=((p+grid[0][0])%K==0)?1:0;
        }
        
        for(int m=0;m<=M;++m){
            for(int n=0;n<=N;++n){

                if(m==0 && n==0) continue; 
                for(int p=K-1;p>=0;--p){

                    long long count=0;  //(p+grid[m][n]%K)%MOD
                    if(m>0) count=(count+dp[m-1][n][(p+grid[m][n])%K])%MOD;
                    if(n>0) count=(count+dp[m][n-1][(p+grid[m][n])%K])%MOD;

                    dp[m][n][p]=count;
                }

            }
        }
        return dp[M][N][0];
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        M=grid.size();
        N=grid[0].size();
        K=k;
        
        return solve(M-1,N-1,grid,0);
    }
};