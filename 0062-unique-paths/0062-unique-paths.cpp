class Solution {
public:  
    int solve(int M, int N){
        vector<int>prev(N+1,-1);
        // dp[0][0]=1;
        //upr->(m-1,n) and left->(m,n-1)

        for(int m=0;m<=M;++m){
            vector<int>curr(N+1,-1);
            for(int n=0;n<=N;++n){
                if(m==0 && n==0){
                    curr[0]=1;
                    continue;
                }
                int count=0;
                if(m-1>=0)  count+=prev[n];
                if(n-1>=0)  count+=curr[n-1];
                curr[n]=count;
            }
            swap(prev,curr);
        }
        return prev[N];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1);  
    }
};