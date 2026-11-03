class Solution {
public:
    int X;
    int MOD=1e9+7;
    vector<long long> powerOf;
    
    void findPow(int n){
        powerOf.resize(n+1);

        for(int v=1;v<=n;v++){
            powerOf[v]=pow(v,X);
        }
    }


    int solve(int N){ 
        vector<vector<int>>dp(N+1  ,vector<int>(N+2,-1));

        for(int start=0;start<N+2;start++){
            dp[0][start]=1;
        }
        
        for(int n=1;n<=N;n++){
            for(int V=N;V>=1;V--){

                long long ways=0;
                for(int v=V; v<=n; v++){
                    long long n_=n-powerOf[v];
                    if(n_<0) break;
                    ways=(ways+dp[n_][v+1])%MOD;
                }
                dp[n][V]=ways;
            }
        }    
        return dp[N][1];
    }

    int numberOfWays(int n, int x) {
        X=x;
        findPow(n);
        return solve(n);   
    }
};