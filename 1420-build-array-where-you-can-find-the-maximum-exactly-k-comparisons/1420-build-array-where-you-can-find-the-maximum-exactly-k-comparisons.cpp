class Solution {
public:
    int M;
    int MOD=1e9+7;

    int solve(int o_n, int o_maxi, int o_k){

        // vector<vector<vector<int>>>dp(o_n+1,vector<vector<int>>(o_maxi+1,vector<int>(o_k+1,0)));

        vector<vector<int>>prev(o_maxi+1,vector<int>(o_k+1,0));

        for(int m=0;m<=o_maxi;m++){
            prev[m][0]=1;
        }

        for(int n=1;n<=o_n;n++){
            vector<vector<int>>curr(o_maxi+1,vector<int>(o_k+1,0));
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
                        if(newK>=0) count=(count+prev[newMax][newK])%MOD;
                    }

                    curr[maxi][k]=count;
                }
            }
            swap(prev,curr);
        }

        return prev[0][o_k];
    }

    int numOfArrays(int n, int m, int k) {
        return solve(n,m,k);
    }
};