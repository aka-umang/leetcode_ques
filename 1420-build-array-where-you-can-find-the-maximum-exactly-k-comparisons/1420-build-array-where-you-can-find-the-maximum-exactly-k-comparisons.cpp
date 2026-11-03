class Solution {
public:
    int M;
    int MOD=1e9+7;

    int solve(int o_n, int o_maxi, int o_k){

        vector<vector<vector<int>>>dp(o_n+1,
            vector<vector<int>>(o_maxi+1,
                vector<int>(o_k+1,-1)
            )
        );

        for(int m=0;m<=o_maxi;m++){
            dp[0][m][0]=1;
        }
        
        for(int m=0;m<=o_maxi;m++){
            for(int k=1;k<=o_k;k++){
                dp[0][m][k]=0;
            }
        }

        for(int n=1;n<=o_n;n++){
            for(int maxi=o_maxi;maxi>=0;maxi--){
                for(int k=0;k<=o_k;k++){

                    long long count=0;

                    for(int i=1;i<=o_maxi;i++){
                        int newMax=maxi;
                        int newK=k;
            
                        if(maxi<i){
                            newMax=i;
                            newK--;
                        }
                        if(newK>=0) count=(count+dp[n-1][newMax][newK])%MOD;
                    }

                    dp[n][maxi][k]=count;
                }
            }
        }

        return dp[o_n][0][o_k];
    }

    int numOfArrays(int n, int m, int k) {
        return solve(n,m,k);
    }
};