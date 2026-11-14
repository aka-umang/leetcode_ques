class Solution {
public:
    int n;

    int solve(vector<vector<int>>& grid){
        
        vector<int>next(n+1,0);
        
        for(int r=n-1;r>=0;r--){
            vector<int>curr(n+1,0);

            for(int skipCol=0; skipCol<=n;skipCol++){

                int minSum=INT_MAX;
                for(int j=0;j<n;j++){
                    if(j==skipCol) continue;
                    int downSum= next[j];
                    minSum=min(minSum, grid[r][j]+downSum);
                }

                curr[skipCol]=minSum;
            }
            swap(next,curr);
        }
        return next[n];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid[0].size();

        return solve(grid);
    }
};