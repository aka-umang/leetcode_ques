class Solution {
public:
    int N;
    int MOD=1e9+7;

    long long solve(int steps,int x,int pos){
        // vector<vector<int>>dp(steps+1,vector<int>(x+1,0));
        vector<int>prev(x+1,0);
        prev[0]=1;
        
        for(int step=1;step<=steps;step++){
            vector<int>curr(x+1,0);
            for(int p=x-1;p>=0;p--){
                int stay=  prev[p];
                int right=  prev[p+1];
                int left=   (p-1<0)?  0:  prev[p-1];

                curr[p]=(0LL+left+right+stay)%MOD;
            }
            swap(prev,curr);
        }
        return prev[0];
    }

    int numWays(int steps, int arrLen) {
        N=arrLen;
        int x=min(steps,N);
        return solve(steps,x,0);
    }
};