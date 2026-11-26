class Solution {
public:
    int m,n;
    
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++)   dp[m][i]=0;

        for(int r=m-1;r>=0;r--){
            for(int p=0;p<=n;p++){

                int mini=INT_MAX;
                for(int j=0;j<n;j++){

                    int d=dp[r+1][j];
                    int cost=0;
                    if(p!=n && r!=0){
                        int temp=grid[r-1][p];
                        cost+=moveCost[temp][j];
                    }
                    mini=min(mini,grid[r][j]+d+cost);

                }
                dp[r][p] =mini;
            }
        }

        return dp[0][n];
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m=grid.size();
        n=grid[0].size();
        
        
        return solve(grid,moveCost);
    }
};