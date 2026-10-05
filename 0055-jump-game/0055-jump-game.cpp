class Solution {
public:
    int N;
    bool solveMemo(vector<int>&dp, vector<int>& nums,int i){
        if(i>=N) return false;
        if(i==N-1) return dp[i]=true;
        
        if(dp[i]!=-1) return false;
        for(int j=i+1; j<N && j<=i+nums[i]; j++){
            if(solveMemo(dp,nums,j)) return dp[i]=true;
        }
        return dp[i]=false;
    }

    

    bool canJump(vector<int>& nums) {
        N=nums.size();
        vector<int>dp(N,-1);
        return solveMemo(dp,nums,0);
    }
};