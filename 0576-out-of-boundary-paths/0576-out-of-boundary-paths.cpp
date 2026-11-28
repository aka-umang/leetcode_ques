class Solution {
public:
    int M,N; 
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int MOD=1e9+7;

    long long solve(int Sr,int Sc, int maxMove){
        vector<vector<vector<int>>>dp(M,
            vector<vector<int>>(N,
                vector<int>(maxMove+1,0)
            )
        );

        for(int moves=1;moves<=maxMove;moves++){
            for(int r=0;r<M;r++){
                for(int c=0;c<N;c++){
        
                    long long ways=0;
                    for(int d=0;d<4;d++){
                        int i=r+dir[d].first;
                        int j=c+dir[d].second;
            
                        if((i<0 || i>=M || j<0 ||j>=N) && moves>=1) ways+=1;

                        else if(moves>=1){
                            ways=(ways+dp[i][j][moves-1])%MOD;
                        }
                        dp[r][c][moves]=ways;
                    }
                }
            }
        }
        return dp[Sr][Sc][maxMove];
    }

    int findPaths(int m, int n, int maxMove, int r, int c) {
        M=m,N=n;
        
        return solve(r,c,maxMove);
    }

};