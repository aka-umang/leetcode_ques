class Solution {
public:
    int n;
    vector<pair<int,int>>dir={{1,-1},{1,0},{1,1}};
    bool isValid(int i,int j){
        return (i>=0 && j>=0 && i<n && j<n);
    }

    int solve(vector<vector<int>> &dp,vector<vector<int>>& mat, int i, int j){

        if(dp[i][j]!=INT_MIN) return dp[i][j];
        
        int minSum=INT_MAX;
        for(int d=0;d<3;d++){
            int r=i+dir[d].first;
            int c=j+dir[d].second;
            if(isValid(r,c)){
                minSum=min(minSum,solve(dp,mat,r,c));
            }
        }
        if(minSum!=INT_MAX) minSum+=mat[i][j];
        if(i==n-1) return dp[i][j]=mat[i][j];

        return dp[i][j]=minSum;
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        n=mat.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int j=0;j<n;j++){
            ans=min(ans,solve(dp,mat,0,j));
        }
        return ans;
    }
};