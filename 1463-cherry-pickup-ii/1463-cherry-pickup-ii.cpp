class Solution {
public:
    int m,n;
    vector<pair<int,int>>dir={{1,0},{1,-1},{1,1}};

    int solve(vector<vector<vector<vector<int>>>>&dp,vector<vector<int>>& grid, int r1,int c1, int r2, int c2){
       
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        if(r1==m-1){
            if(c1==c2) {return grid[r1][c1];}
            return grid[r1][c1]+grid[r2][c2];
        }

        int maxSum=0;

        for(auto& [x,y]:dir){
            int i=r1+x;
            int j=c1+y;
            if(j<0 || j==n) continue;

            for(auto& [a,b]:dir){
                int i_=r2+a;
                int j_=c2+b;
                if(j_<0 || j_==n) continue;
                maxSum=max(maxSum,solve(dp,grid,i,j,i_,j_));
            }
        }
        if (c1==c2) maxSum += grid[r1][c1];
        else    maxSum += grid[r1][c1] + grid[r2][c2];

        return dp[r1][c1][r2][c2]=maxSum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<vector<int>>>>dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(n,-1))));
        return solve(dp,grid,0,0,0,n-1);
    }
};