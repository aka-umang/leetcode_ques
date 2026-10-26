class Solution {
public:
    int M,N,K;
    
    int solve(vector<vector<int>>& grid){
        vector<vector<vector<int>>> dp(M+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));

        for(int j=0;j<=N;j++){
            for(int k=0;k<=K;k++) {
                dp[M][j][k]=-1;
            }
        }
        
        for(int i=0;i<=M;i++){
            for(int k=0;k<=K;k++) {
                dp[i][N][k]=-1;
            }
        }
        
        for(int k=0;k<=K;k++){
            // dp[M-1][N-1][k]=(grid[M-1][N-1]!=0 && k-1<0)?-1: grid[M-1][N-1];
            if(k>0 || (k==0 && grid[M-1][N-1]==0)) dp[M-1][N-1][k]=grid[M-1][N-1];
            else dp[M-1][N-1][k]=-1;
        }
        
        for(int i=M-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){      
                for(int k=0;k<=K;k++){
                    if(i==M-1 && j==N-1) continue;

                    int k_=(grid[i][j]!=0)?k-1:k;

                    int down=(k_>=0)? dp[i+1][j][k_]: -1;
                    int right=(k_>=0)? dp[i][j+1][k_]: -1;
                    int score =max(down,right);
                
                    dp[i][j][k]=(score==-1)?-1:grid[i][j]+score;
                }
            }
        }

        return dp[0][0][K];       
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        M=grid.size();
        N=grid[0].size();
        K=k;
        return solve(grid);
    }
};