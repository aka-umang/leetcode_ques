class Solution {
public:
    int M,N; 
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int MOD=1e9+7;

    long long solve(vector<vector<vector<int>>>&dp,int r,int c, int moves){
        if(dp[r][c][moves]!=-1) return dp[r][c][moves];
        long long ways=0;
        for(int d=0;d<4;d++){
            int i=r+dir[d].first;
            int j=c+dir[d].second;
            
            if((i<0 || i>=M || j<0 ||j>=N) && moves>=1) ways+=1;

            else if(moves>=1){
                ways=(ways+solve(dp,i,j,moves-1))%MOD;
            }
        }
        return dp[r][c][moves]=ways;
    }

    int findPaths(int m, int n, int maxMove, int r, int c) {
        M=m,N=n;
        vector<vector<vector<int>>>dp(m,
            vector<vector<int>>(n,
                vector<int>(maxMove+1,-1)
            )
        );
        return solve(dp,r,c,maxMove);
    }

};