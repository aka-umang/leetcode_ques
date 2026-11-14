class Solution {
public:
    int m,n;
    int Target;

    int solve( vector<vector<int>>& mat){
        vector<vector<int>>dp(m+1,vector<int>(4901,0));

        for(int pathSum=0;pathSum<=4900;pathSum++) dp[m][pathSum]= abs(pathSum-Target);

        for(int r=m-1;r>=0;r--){
            for(int pathSum=4900;pathSum>=0;pathSum--){
                int mini=INT_MAX;
                for(int j=0;j<n;j++){
                    int nextSum = pathSum + mat[r][j];

                    if(nextSum <= 4900) {
                        mini = min(mini, dp[r+1][nextSum]);
                    }
                }
                dp[r][pathSum]=mini;
            }
        }
        return dp[0][0];
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m=mat.size();
        n=mat[0].size();
        Target=target;

        return solve(mat);
    }
};