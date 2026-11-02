class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(); 
        int m=mat[0].size();
        //multi-source BFS over 0's
        queue<pair<int,int>> que;
        
        vector<vector<int>> res(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    que.push({i,j});
                    res[i][j]=0;
                }
            }
        }

        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        int l=1;
        while(!que.empty()){
            int k=que.size();
            while(k--){
                auto cell=que.front(); que.pop();
                int i=cell.first;
                int j=cell.second;
                for(int d=0;d<4;d++){
                    int r=i+dir[d].first;
                    int c=j+dir[d].second;
                    if(r<0 || r>=n || c<0 ||c>=m) continue;
                    if(mat[r][c]==0) continue;
                    if(res[r][c]==INT_MAX) {
                        que.push({r,c});
                        res[r][c]=min(res[r][c],l);
                    }       
                }
            }
            l++;
        }

        return res;
    }
};