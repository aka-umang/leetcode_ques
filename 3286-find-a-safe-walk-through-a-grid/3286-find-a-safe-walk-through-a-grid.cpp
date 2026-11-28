class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(); 
        int n=grid[0].size();
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));

        deque<tuple<int,int,int>> que;//<cost_till,i,j>
        if(grid[0][0]==1) que.push_back({1,0,0});
        else que.push_back({0,0,0});
        
        res[0][0]=(grid[0][0]==1)?1:0;

        while(!que.empty()){
            auto [cost,I,J]=que.front();
            que.pop_front();
            if(cost>health) continue;
            if(I==m-1 && J==n-1) {
                if(cost<health) return true;
            }

            for(int d=0;d<4;d++){
                int i=I+dir[d].first;
                int j=J+dir[d].second;
                if(i<0||j<0||i>=m||j>=n) continue;
               
                if(grid[i][j]==1 && res[i][j]>cost+1){
                    que.push_back({cost+1,i,j});
                    res[i][j]=cost+1;
                }
                else if(grid[i][j]==0 && res[i][j]>cost){
                    que.push_front({cost,i,j});
                    res[i][j]=cost;
                }
            }
        }
        return false;
    }
};