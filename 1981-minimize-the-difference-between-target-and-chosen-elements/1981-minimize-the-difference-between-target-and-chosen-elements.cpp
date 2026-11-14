class Solution {
public:
    int m,n;
    int Target;

    int solve( vector<vector<int>> &dp,vector<vector<int>>& mat, int r, int pathSum){

        if(dp[r][pathSum]!=-1) return dp[r][pathSum];

        if(r==m){
            return abs(pathSum-Target);
        }

        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            int down=solve(dp,mat,r+1,pathSum+mat[r][j]);
            mini=min(mini,down);
        }
        return dp[r][pathSum]=mini;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m=mat.size();
        n=mat[0].size();
        Target=target;
        vector<vector<int>>dp(m+1,vector<int>(56001,-1));
        return solve(dp,mat,0,0);
    }
};