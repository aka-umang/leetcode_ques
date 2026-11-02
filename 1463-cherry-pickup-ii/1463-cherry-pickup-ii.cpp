class Solution {
public:
    int m,n;
    vector<pair<int,int>>dir={{1,0},{1,-1},{1,1}};

    int solve(vector<vector<int>>& grid){


        vector<vector<int>>next(n, //R+1th table
            vector<int>(n,-1)
        );

        for(int r=m-1;r>=0;r--){
            vector<vector<int>>curr(n, //Rth table
                vector<int>(n,-1)
            );

            for(int c1=n-1;c1>=0;c1--){
                for(int c2=0;c2<=n-1;c2++){

                    int maxSum=0;
                    for(auto& [x,y]:dir){
                        int i=r+x;
                        int j=c1+y;
                        if(i==m ||j<0 || j==n) continue;

                        for(auto& [a,b]:dir){
                            int i_=r+a;
                            int j_=c2+b;
                            if(i_==m || j_<0 || j_==n) continue;
                            maxSum=max(maxSum,next[j][j_] );
                        }
                    }

                    curr[c1][c2] =maxSum + grid[r][c1] + (c1 == c2 ? 0 : grid[r][c2]);
                }
            }
            swap(next,curr);
        }
        return next[0][n-1];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>>dp(m,
            vector<vector<int>>(n,
                vector<int>(n,-1)
            )
        );
        return solve(grid);
    }
};