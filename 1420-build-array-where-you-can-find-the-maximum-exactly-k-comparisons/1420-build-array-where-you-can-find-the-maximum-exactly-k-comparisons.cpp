class Solution {
public:
    int M;
    int MOD=1e9+7;

    int solve(vector<vector<vector<int>>>&dp,int n, int maxi, int k){
        
        if(n==0){
            return (k==0)?1:0;
        }

        if(dp[n][maxi][k]!=-1) return dp[n][maxi][k];

        long long count=0;
        for(int i=1;i<=M;i++){
            if(maxi<i){
                if(k>0) count=(count+solve(dp,n-1,i,k-1))%MOD;
            }
            else{
                count=(count+solve(dp,n-1,maxi,k))%MOD;
            }
        }

        return dp[n][maxi][k]=count;
    }

    int numOfArrays(int n, int m, int k) {
        M=m;
        
        vector<vector<vector<int>>>dp(n+1,
            vector<vector<int>>(m+1,
                vector<int>(k+1,-1)
            )
        );

        return solve(dp,n,0,k);
    }
};