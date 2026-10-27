class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        queue<pair<int,int>> que;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
            }
        }

        int ans= bfs(que,grid);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return ans;
    }

    int bfs(queue<pair<int,int>> &que,vector<vector<int>>& grid){
        int l=0;
        while(!que.empty()){
            int k=que.size();
            while(k--){
                auto [i,j]=que.front(); que.pop();
                for(int d=0;d<4;d++){
                    int r=i+dir[d].first;
                    int c=j+dir[d].second;
                    if(r<0 || c<0 || r>=m || c>=n) continue;
                    if(grid[r][c]==1){
                        grid[r][c]=-1;
                        que.push({r,c});
                    }

                }
            } 
            l++;
        }
        if(l==0) return 0;
        return l-1;
    }
};