class Solution {
public:
    int m,n;
    
    int solve(vector<vector<int>>&dp,vector<vector<int>>& triangle){
    
        // for(int j=0;j<n;j++){
        //     dp[m-1][j]=triangle[m-1][j];
        // }
        
        for(int i=m-2;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                int d=triangle[i+1][j];
                int dr=triangle[i+1][j+1];
                triangle[i][j]= triangle[i][j]+min(d,dr);
            }
        }

       return triangle[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        n=triangle[m-1].size();

        vector<vector<int>>dp;

        for(int s=1;s<=m;s++){
            vector<int>temp(s,INT_MIN);
            dp.push_back(temp);
        }
        return solve(dp,triangle);
    }
};