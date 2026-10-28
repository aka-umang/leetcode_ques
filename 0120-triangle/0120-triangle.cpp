class Solution {
public:
    int m,n;
    
    int solve(vector<vector<int>>& triangle){
        vector<vector<int>>dp(m,vector<int>(n,INT_MIN));

        for(int j=0;j<n;j++){
            dp[m-1][j]=triangle[m-1][j];
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                int d=dp[i+1][j];
                int dr=dp[i+1][j+1];
                dp[i][j]= triangle[i][j]+min(d,dr);
            }
        }

       return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        n=triangle[m-1].size();
        return solve(triangle);
    }
};