class Solution {
public:
    
    int solve(int M, int N){
        vector<vector<int>>dp(M+1,vector<int>(N+1,-1));
        dp[0][0]=1;
        // if(m<0 || n<0) return 0;

        //upr->(m-1,n) and left->(m,n-1)

        for(int m=0;m<=M;++m){
            for(int n=0;n<=N;++n){
                if(m==0 && n==0){
                    continue;
                }
                int count=0;
                if(m-1>=0)  count+=dp[m-1][n];
                if(n-1>=0)  count+=dp[m][n-1];
                dp[m][n]=count;
            }
        }
        return dp[M][N];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1);  
    }
};