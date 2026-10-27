class Solution {
public:
    int n;
    int m;
    vector<vector<int>> h;
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //multi-source-DFS-typeQuestion
        h=heights;
        n=heights.size();
        m=heights[0].size();
        vector<vector<bool>> paci(n,vector<bool>(m,false));
        vector<vector<bool>> atlan(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            paci[i][0]=true;
            dfs(i,0,paci);

            atlan[i][m-1]=true;
            dfs(i,m-1,atlan);
        }
        for(int j=1;j<m;j++) {
            paci[0][j]=true;
            dfs(0,j,paci);
        }
        for(int j=0;j<m-1;j++){
            atlan[n-1][j]=true;
            dfs(n-1,j,atlan);
        }

        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paci[i][j] && atlan[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
    
    void dfs(int i,int j,vector<vector<bool>>&visited){  
        for(int d=0;d<4;d++){
            int r=i+dir[d].first;
            int c=j+dir[d].second;
            if(r<0 || c<0 ||r>=n ||c>=m) continue;
            if(visited[r][c]==true) continue;
            if(h[i][j]>h[r][c]) continue;
            visited[r][c]=true;
            dfs(r,c,visited);
        }
    }
};