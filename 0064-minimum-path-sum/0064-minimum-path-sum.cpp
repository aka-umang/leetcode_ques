class Solution {
public:
    int m,n;

    int solve2D(vector<vector<int>>& grid){
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        // dp[m-1][n-1]=grid[m-1][n-1];

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;

                int down=(i+1==m)?INT_MAX:grid[i+1][j];
                int right=(j+1==n)?INT_MAX:grid[i][j+1];

                int mini=min(down,right);
                if(mini!=INT_MAX)  mini+=grid[i][j];
                grid[i][j]=mini;
            }
        }

        return grid[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        return solve2D(grid);
    }
};