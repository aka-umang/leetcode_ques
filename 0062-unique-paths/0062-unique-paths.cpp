class Solution {
public:
    
    int solve(vector<vector<int>>&dp, int m, int n){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        //upr->(m-1,n) and left->(m,n-1)
        if(dp[m][n]!=-1) return dp[m][n];
        int count=0;
        count+=solve(dp,m-1,n);
        count+=solve(dp,m,n-1);
        return dp[m][n]=count;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(dp,m-1,n-1);  
    }
};