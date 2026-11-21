class Solution {
public:
    int m,n;
    vector<pair<int,int>> adj={{1,0},{-1,0},{0,1},{0,-1}};

    void solve(vector<vector<int>>& heights, vector<vector<bool>> &water, int i, int j){
        water[i][j]=true;
        for(int d=0;d<4;d++){
            int r=i+adj[d].first;
            int c=j+adj[d].second;
            if(r<0 || c<0 || r==m || c==n || water[r][c] || heights[i][j]>heights[r][c]) continue;
            solve(heights,water,r,c);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();

        vector<vector<int>>result;

        vector<vector<bool>> paci(m,vector<bool>(n,false));
        vector<vector<bool>> atlan(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0   || j==0){
                    paci[i][j]=true;
                    solve(heights,paci,i,j);
                }
                if(i==m-1 || j==n-1){
                    atlan[i][j]=true;
                    solve(heights,atlan,i,j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(paci[i][j] && atlan[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};