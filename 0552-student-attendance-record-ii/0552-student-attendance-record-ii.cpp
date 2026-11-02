class Solution {
public: 
    int MOD=1e9+7;

    int solve(int N){
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(3,-1)));

        for(int a=0;a<2;a++){
            for(int ls=0;ls<3;ls++){
                dp[0][a][ls]=1;
            }
        }

        
        for(int n=1;n<=N;n++){
            for(int a=1;a>=0;a--){
                for(int ls=2;ls>=0;ls--){

                    long long ans=dp[n-1][a][0]; //p place kiya
                    if(a<1) ans=(ans+dp[n-1][a+1][0])%MOD; //A place kiya
                    if(ls<2) ans=(ans+dp[n-1][a][ls+1])%MOD; //L place kiya
                    dp[n][a][ls]=ans;

                }
            }
        }

        return dp[N][0][0];
    }

    int checkRecord(int n){
        return solve(n);
    }
};