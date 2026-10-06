class Solution {
public:
    int n;
    int tabulation(vector<int>& nums){
        vector<int>dp(n,0);
        
        for(int i=n-2;i>=0;i--){
            int minCost=n;
            for(int j=i+1;j<n && j<=i+nums[i]; j++){
                minCost=min(minCost,1+dp[j]);
            }
            dp[i]=minCost;
        }
        return dp[0];
    }

    int jump(vector<int>& nums) {
        n=nums.size();
        return tabulation(nums);
    }
};