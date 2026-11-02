class Solution {
public: 
    int MOD=1e9+7;

    int solve(int N){
        // vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(3,1)));

        vector<vector<int>>prev(2,vector<int>(3,1));
        
        for(int n=1;n<=N;n++){
            vector<vector<int>>curr(2,vector<int>(3,1));

            for(int a=1;a>=0;a--){
                for(int ls=2;ls>=0;ls--){

                    long long ans=prev[a][0]; //p place kiya
                    if(a<1) ans=(ans+prev[a+1][0])%MOD; //A place kiya
                    if(ls<2) ans=(ans+prev[a][ls+1])%MOD; //L place kiya
                    curr[a][ls]=ans;

                }
            }
            swap(prev,curr);
        }

        return prev[0][0];
    }

    int checkRecord(int n){
        return solve(n);
    }
};