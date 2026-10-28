class Solution {
public:
    int m,n;
   
    bitset<1024> solve(vector<vector<bitset<1024>>> &dp,vector<vector<bool>> &vis,vector<vector<int>>& grid, int i, int j){
        if(i==m-1 && j==n-1){
            bitset<1024> s;
            s.set(grid[i][j]);
            return s;
        }

        if(i==m || j==n) {
            bitset<1024> s;
            return s;
        } 

        if(vis[i][j]) return dp[i][j];

        bitset<1024> d=solve(dp,vis,grid,i+1,j);
        bitset<1024> r=solve(dp,vis,grid,i,j+1);
        r=r|d;

        bitset<1024> ans;
        for(int x=0;x<1024;x++){
            if(r[x]){
                int idx=x^grid[i][j];
                ans[idx]=1;
            }
        }

        vis[i][j]=true;
        return dp[i][j]=ans;
    }

    int minCost(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)
        );

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        bitset<1024> ans= solve(dp,vis,grid,0,0);

        for(int i=0;i<1024;i++){
            if(ans[i]==1) return i;
        }    
        return grid[0][0];
    }
};