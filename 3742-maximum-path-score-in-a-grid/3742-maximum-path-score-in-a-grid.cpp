class Solution {
public:
    int M,N,K;
    
    int solve(vector<vector<int>>& grid){
        
        vector<vector<int>>next_row(N+1,vector<int>(K+1,-1));
        
        for(int k=0;k<=K;k++){
            if(k>0 || (k==0 && grid[M-1][N-1]==0))  next_row[N-1][k]=grid[M-1][N-1];
            else next_row[N-1][k]=-1;
        }
        
        for(int i=M-1;i>=0;i--){
           vector<vector<int>>curr_row(N+1,vector<int>(K+1,-1));

            for(int j=N-1;j>=0;j--){      
                for(int k=0;k<=K;k++){

                    if(i==M-1 && j==N-1){
                        if(k>0 || (k==0 && grid[M-1][N-1]==0))  {curr_row[N-1][k]=grid[M-1][N-1];}
                        else {curr_row[N-1][k]=-1;}
                        
                        continue;
                    }

                    int k_=(grid[i][j]!=0)?k-1:k;

                    int down  =  (k_>=0)?  next_row[j][k_]   :   -1;
                    int right =  (k_>=0)?  curr_row[j+1][k_] :   -1;

                    int score =max(down,right);
                
                    curr_row[j][k]=(score==-1)?-1:grid[i][j]+score;
                }
            }
            swap(next_row,curr_row);
        }

        return next_row[0][K];       
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        M=grid.size();
        N=grid[0].size();
        K=k;
        return solve(grid);
    }
};