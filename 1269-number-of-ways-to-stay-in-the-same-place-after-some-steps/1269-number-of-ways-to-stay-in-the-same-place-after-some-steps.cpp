class Solution {
public:
    int N;
    int MOD=1e9+7;

    long long solve(int steps,int x,int pos){
        vector<vector<int>>dp(steps+1,vector<int>(x+1,0));
        dp[0][0]=1;
        
        for(int step=1;step<=steps;step++){
            for(int p=x-1;p>=0;p--){
                int stay=   dp[step-1][p];
                int right=  (p+1>x)?  0:  dp[step-1][p+1];
                int left=   (p-1<0)?  0:  dp[step-1][p-1];

                dp[step][p]=(0LL+left+right+stay)%MOD;
            }
        }
        return dp[steps][0];
    }

    int numWays(int steps, int arrLen) {
        N=arrLen;
        int x=min(steps,N);
        return solve(steps,x,0);
    }
};