class Solution {
public:
    int n;
    int solveRec(vector<int>&dp,vector<int>& nums, int i){
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int minCost=n;
        for(int j=i+1;j<n && j<=i+nums[i]; j++){
            minCost=min(minCost,1+solveRec(dp,nums,j));
        }
        return dp[i]=minCost;
    }

    int jump(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n,-1);
        return solveRec(dp,nums,0);
    }
};