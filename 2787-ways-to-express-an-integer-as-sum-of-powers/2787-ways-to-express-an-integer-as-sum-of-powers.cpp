class Solution {
public:
    int X;
    int MOD=1e9+7;

    int solve(vector<vector<int>> &dp, int n, int V){  
        if(n==0) return 1;

        if(dp[n][V]!=-1) return dp[n][V];

        int ways=0;
        for(int v=V; v<=n; v++){
            int n_=n-pow(v,X);
            if(n_<0) break;
            ways=(ways+solve(dp,n_,v+1))%MOD;
        }
        return dp[n][V]=ways;
    }

    int numberOfWays(int n, int x) {
        X=x;
        vector<vector<int>>dp(n+1  ,vector<int>(n+1,-1));
        return solve(dp,n,1);   
    }
};