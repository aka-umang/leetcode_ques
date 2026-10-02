class Solution {
public:
    // int solveRec(int n){
    //     if(n==0) return 0;
    //     if(n==1 || n==2) return 1;

    //     return solveRec(n-1)+solveRec(n-2)+solveRec(n-3);
    // }

    int solveRecMemo(vector<int>&dp, int n){
        if(n==0) return dp[n]=0;
        if(n==1 || n==2) return dp[n]=1;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=solveRecMemo(dp,n-1)+solveRecMemo(dp,n-2)+solveRecMemo(dp,n-3);
    }

    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return solveRecMemo(dp,n); 
    }
};