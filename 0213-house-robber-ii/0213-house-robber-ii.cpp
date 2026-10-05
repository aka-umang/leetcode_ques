class Solution {
public:
    int solveMemo(vector<int>& dp,vector<int>& nums,int start,int end){
        if(start>end) return 0;
        if(dp[start]!=-1) return dp[start];

        int stole=nums[start]+solveMemo(dp,nums,start+2,end);
        int notStole=solveMemo(dp,nums,start+1,end);
        return dp[start]=max(stole,notStole);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int startFrom0=solveMemo(dp1,nums,0,n-2);
        int startFrom1=solveMemo(dp2,nums,1,n-1);
        return max(startFrom0,startFrom1);
    }
};