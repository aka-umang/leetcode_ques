class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //multi-source-BFS-Traversal...
        queue<pair<int,int>>que;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) que.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        int min=0;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(que.size()>0){
            int k=que.size();
            if(fresh==0) break;
            while(k--){
                auto cell=que.front(); que.pop();
                int i=cell.first;
                int j=cell.second;
                for(int d=0;d<4;d++){
                    int r=i+dir[d].first;
                    int c=j+dir[d].second;
                    if(r<0 || c<0 ||r>=n ||c>=m) continue;
                    if(grid[r][c]==2 || grid[r][c]==0) continue;
                    fresh--;
                    grid[r][c]=2;
                    que.push({r,c});
                }
            }
            min++;
        }
        if(fresh>0) return -1;
        return min;
    }
};