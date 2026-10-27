class Solution {
public:
    int n;
    int m;
    vector<vector<int>> h;
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //multi-source-BFS-typeQuestion
        h=heights;
        n=heights.size();
        m=heights[0].size();

        queue<pair<int,int>>pacific;
        queue<pair<int,int>>atlantic;


        for(int i=0;i<n;i++){
            pacific.push({i,0});
            atlantic.push({i,m-1});
        }

        for(int j=1;j<m;j++) pacific.push({0,j});
        for(int j=0;j<m-1;j++) atlantic.push({n-1,j});       

        vector<vector<bool>> paci=bfs(pacific);
        vector<vector<bool>> atlan=bfs(atlantic);

        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paci[i][j] && atlan[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }

    vector<vector<bool>> bfs(queue<pair<int,int>> &que){
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        while(que.size()>0){
            auto cell=que.front(); que.pop();
            int i=cell.first;
            int j=cell.second;
            visited[i][j]=true;
            for(int d=0;d<4;d++){
                int r=i+dir[d].first;
                int c=j+dir[d].second;
                if(r<0 || c<0 ||r>=n ||c>=m) continue;
                if(h[r][c]<h[i][j]) continue;
                if(visited[r][c]==true) continue; //agr milchuka toh abh mt dekho hme koi mtlb ni
                visited[r][c]=true;
                que.push({r,c});
            }
        }
        return visited;
    }
};