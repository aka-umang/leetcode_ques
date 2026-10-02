class Solution {
public:
    // int solveRec(int n){
    //     if(n==0) return 0;
    //     if(n==1 || n==2) return 1;

    //     return solveRec(n-1)+solveRec(n-2)+solveRec(n-3);
    // }

    // int solveRecMemo(vector<int>&dp, int n){
    //     if(n==0) return dp[n]=0;
    //     if(n==1 || n==2) return dp[n]=1;

    //     if(dp[n]!=-1) return dp[n];

    //     return dp[n]=solveRecMemo(dp,n-1)+solveRecMemo(dp,n-2)+solveRecMemo(dp,n-3);
    // }

    int solveTabu(int n){
        vector<int>dp(n+1);
        dp[0]=0; dp[1]=1; dp[2]=1;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }

    int tribonacci(int n) {
        // solveRec(n);

        // vector<int>dp(n+1,-1);
        // return solveRecMemo(dp,n); 

        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        return solveTabu(n);
    }

};