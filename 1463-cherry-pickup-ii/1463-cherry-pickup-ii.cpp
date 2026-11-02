class Solution {
public:
    int m,n;
    vector<pair<int,int>>dir={{1,0},{1,-1},{1,1}};

    int solve(vector<vector<vector<int>>>&dp,vector<vector<int>>& grid, int r,int c1,int c2){
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];

        int maxSum=0;
        for(auto& [x,y]:dir){
            int i=r+x;
            int j=c1+y;
            if(i==m ||j<0 || j==n) continue;

            for(auto& [a,b]:dir){
                int i_=r+a;
                int j_=c2+b;
                if(i_==m || j_<0 || j_==n) continue;
                maxSum=max(maxSum,solve(dp,grid,i,j,j_));
            }
        }
        return dp[r][c1][c2] =maxSum + grid[r][c1] + (c1 == c2 ? 0 : grid[r][c2]);
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>>dp(m,
            vector<vector<int>>(n,
                vector<int>(n,-1)
            )
        );
        return solve(dp,grid,0,0,n-1);
    }
};