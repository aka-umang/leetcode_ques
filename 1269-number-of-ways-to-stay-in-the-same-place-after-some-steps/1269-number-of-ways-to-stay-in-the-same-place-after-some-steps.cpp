class Solution {
public:
    int N;
    int MOD=1e9+7;

    long long solve(vector<vector<int>>&dp,int steps,int pos){
        if(steps==0){
            if(pos==0) return 1;
            return 0;
        }
        if(pos<0 || pos==N) return 0;

        if(dp[steps][pos]!=-1) return dp[steps][pos];

        int stay=solve(dp,steps-1,pos);
        int right=solve(dp,steps-1,pos+1);
        int left=solve(dp,steps-1,pos-1);
        return dp[steps][pos]=(0LL+left+right+stay)%MOD;
    }

    int numWays(int steps, int arrLen) {
        N=arrLen;
        int x=min(steps,N);
        vector<vector<int>>dp(steps+1,vector<int>(x,-1));
        return solve(dp,steps,0);
    }
};