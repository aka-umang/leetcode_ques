class Solution {
public: 
    int m,n;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    bool solve(vector<vector<vector<int>>> &dp,vector<vector<int>>& grid, int i, int j, int health){
        if(grid[i][j]==1) health--;
        if(health<1) return false;

        if(dp[i][j][health]!=-1) return dp[i][j][health];

        if(i==m-1 && j==n-1) return true;

        int og=grid[i][j];
        grid[i][j]=-1;

        for(int d=0;d<4;d++){
            int r=i+dir[d].first;
            int c=j+dir[d].second;
            if(r<0||c<0||r>=m||c>=n || grid[r][c]==-1) continue;
            
            if(grid[i][j]==1){
                if(health>1 && solve(dp,grid,r,c,health-1)) return dp[i][j][health]=true; 
            }
            else{
                if(solve(dp,grid,r,c,health)) return dp[i][j][health]=true; 
            }
            
        }

        grid[i][j]=og;
        return dp[i][j][health]=false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<vector<int>>> dp(m,
            vector<vector<int>>(n,
                vector<int>(health+1,-1)
            )
        );

        return solve(dp,grid,0,0,health);
    }
};