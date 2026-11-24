class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        queue<pair<int,int>>que;

        for(int i: {0,m-1}){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='Y';
                    que.push({i,j});
                }
            }
        }

        for(int j: {0,n-1}){
            for(int i=0;i<m;i++){
                if(board[i][j]=='O'){
                    board[i][j]='Y';
                    que.push({i,j});
                }
            }
        }

        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        while(!que.empty()){
            auto [i,j]=que.front(); que.pop();
            for(int d=0;d<4;d++){
                int r=i+dir[d].first;
                int c=j+dir[d].second;
                if(r<0||c<0||r>=m||c>=n) continue;
                if(board[r][c]!='O') continue;
                
                board[r][c]='Y';
                que.push({r,c});
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X') continue;

                board[i][j]=(board[i][j]=='Y'?'O':'X');
            }
        }
    }
};