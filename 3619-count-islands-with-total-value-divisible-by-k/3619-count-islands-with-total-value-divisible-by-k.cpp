class Solution {
public:
    int m,n;
    vector<vector<bool>> visit;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& grid, int i,int j,long long& sum){
        sum+=grid[i][j];

        for(int d=0;d<4;d++){
            int r=i+dir[d].first;
            int c=j+dir[d].second;
            if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0 || visit[r][c]) continue;
            visit[r][c]=true;

            dfs(grid,r,c,sum);
        }
    
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        m=grid.size(); n=grid[0].size();
        visit.resize(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && visit[i][j]==false){
                    long long sum=0;
                    visit[i][j]=true;
                    dfs(grid,i,j,sum);
                    if(sum%k==0) ans++;
                }
            }
        }

        return ans;
    }
};