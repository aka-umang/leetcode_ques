class Solution {
public:
    int n;
    vector<pair<int,int>>dir={{1,-1},{1,0},{1,1}};
    
    bool isValid(int i,int j){
        return (i>=0 && j>=0 && i<n && j<n);
    }

    int solve(vector<vector<int>>& mat){
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                int minSum=INT_MAX;
                for(int d=0;d<3;d++){
                    int r=i+dir[d].first;
                    int c=j+dir[d].second;
                    if(isValid(r,c)){
                        minSum=min(minSum,dp[r][c]);
                    }
                }
                if(minSum!=INT_MAX) minSum+=mat[i][j];
                if(i==n-1){
                    dp[i][j]=mat[i][j];
                    continue;
                }
                dp[i][j]=minSum;
            }
        }
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[0][j]);
        }
        return ans;

    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        n=mat.size();
        return solve(mat);
    }
};