class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    long long bfs(vector<vector<int>>& grid, int si, int sj) {
        queue<pair<int,int>> que;

        long long sum = grid[si][sj];   // count the start cell
        grid[si][sj] = 0;               // mark visited immediately
        que.push({si, sj});

        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();

            for (auto [di, dj] : dir) {
                int r = i + di, c = j + dj;
                if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) continue;

                sum += grid[r][c];     
                grid[r][c] = 0;         
                que.push({r, c});
            }
        }
        return sum;                     
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        m=grid.size(); n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long sum=bfs(grid,i,j);
                    if(sum%k==0) ans++;
                }
            }
        }

        return ans;
    }
};