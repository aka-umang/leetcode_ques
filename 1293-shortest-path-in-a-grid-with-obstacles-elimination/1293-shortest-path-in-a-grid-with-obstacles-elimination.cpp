class Solution {
public:
    typedef tuple<int,int,int> Tuple;
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        
        queue<Tuple>que;
        vector<vector<vector<bool>>>visited(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
        que.push({0,0,k}); 
        visited[0][0][k]=true;

        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};

        int l=0;
        while(!que.empty()){
            int x=que.size();
            while(x--){
                auto [i,j,k_]= que.front(); que.pop();
                if(i==m-1 && j==n-1) return l; 

                for(int d=0;d<4;d++){
                    int r=i+dir[d].first;
                    int c=j+dir[d].second;

                    if(r<0 ||c<0 ||r>=m ||c>=n ||(k_==0 && grid[r][c]==1)) continue;
                    if(grid[r][c]==1){
                        if(!visited[r][c][k_-1])  {
                            que.push({r,c,k_-1});
                            visited[r][c][k_-1]=true;
                        }
                    }
                    else{
                        if(!visited[r][c][k_])  {
                            que.push({r,c,k_});
                            visited[r][c][k_]=true;
                        }
                    }
                }
            }
            l++;
        }
        return -1;
    }
};