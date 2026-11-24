class Solution {
public:
    int  m,n;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();

        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>que;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    que.push({i,j});
                }
            }
        }

        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!que.empty()){
            auto [i,j]=que.front(); que.pop();
            for(int d=0;d<4;d++){
                int r=i+dir[d].first;
                int c=j+dir[d].second;
                if(r<0||c<0||r>=m||c>=n) continue;
                if(ans[r][c]==INT_MAX){
                    ans[r][c]=1+ans[i][j];
                    que.push({r,c});
                }
            }
        }
        return ans;
    }
};