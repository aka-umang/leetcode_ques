class Solution {
public: 
    int MOD=1e9+7;

    int solve(vector<vector<vector<int>>> &dp,int n, int A, int Ls){
        if(n==0) return 1;
        if(dp[n][A][Ls]!=-1) return dp[n][A][Ls];

        long long ans=solve(dp,n-1,A,0); //p place kiya
        if(A<1) ans=(ans+solve(dp,n-1,A+1,0))%MOD; //A place kiya
        if(Ls<2) ans=(ans+solve(dp,n-1,A,Ls+1))%MOD; //L place kiya

        return dp[n][A][Ls]=ans;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(dp,n,0,0); //idx, A_count, consecutive_L_count;
    }
};