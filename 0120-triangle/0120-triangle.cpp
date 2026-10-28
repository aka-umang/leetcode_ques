class Solution {
public:
    int m;
    int solve(vector<vector<int>>&dp,vector<vector<int>>& triangle, int i, int j){
        if(i==m-1) return triangle[i][j];

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int d=solve(dp,triangle,i+1,j);
        int dr=solve(dp,triangle,i+1,j+1);

        return dp[i][j]= triangle[i][j]+min(d,dr);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MIN));
        return solve(dp,triangle,0,0);
    }
};