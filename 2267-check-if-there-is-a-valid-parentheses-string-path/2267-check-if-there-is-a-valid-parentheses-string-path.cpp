class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,-1},{0,1}};

    bool path(vector<vector<vector<int>>>&dp,vector<vector<char>>& grid ,int i, int j,int c){
        if(i>=m || j>=n) return false;
        if(c<0) return false;

        if(dp[i][j][c]!=-1) return dp[i][j][c];

        if(i==m-1 && j==n-1){
            c=(grid[i][j]=='(')?c+1:c-1;
            return (c==0)?true:false;
        }

        bool down=path(dp,grid,i+1,j,(grid[i][j]=='(')?c+1:c-1);
        bool right=path(dp,grid,i,j+1,(grid[i][j]=='(')?c+1:c-1);
        
        return dp[i][j][c]=down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int LIMIT=m+n; //maxStack length

        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(LIMIT,-1)));
        return path(dp,grid,0,0,0);
    }
};