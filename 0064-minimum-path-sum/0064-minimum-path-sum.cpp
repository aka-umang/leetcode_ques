class Solution {
public:
    int m,n;

    int solve2D(vector<vector<int>>& grid){
        vector<int>next(n+1,INT_MAX);

        for(int i=m-1;i>=0;i--){
            vector<int>curr(n+1,INT_MAX);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) {
                    curr[n-1]=grid[m-1][n-1];
                    continue;
                }

                int down=next[j];
                int right=curr[j+1];

                int mini=min(down,right);
                if(mini!=INT_MAX)  mini+=grid[i][j];
                curr[j]=mini;
            }
            swap(curr,next);
        }

        return next[0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        return solve2D(grid);
    }
};