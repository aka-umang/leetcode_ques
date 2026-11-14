class Solution {
public:
    int m,n;
    int Target;

    int solve( vector<vector<int>>& mat){
        vector<int>next(4901,0);

        for(int pathSum=0;pathSum<=4900;pathSum++) next[pathSum]= abs(pathSum-Target);

        for(int r=m-1;r>=0;r--){
            vector<int>curr(4901,0);

            for(int pathSum=4900;pathSum>=0;pathSum--){
                int mini=INT_MAX;
                for(int j=0;j<n;j++){
                    int nextSum = pathSum + mat[r][j];

                    if(nextSum <= 4900) {
                        mini = min(mini, next[nextSum]);
                    }
                }
                curr[pathSum]=mini;
            }
            swap(next,curr);
        }

        return next[0];
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m=mat.size();
        n=mat[0].size();
        Target=target;

        return solve(mat);
    }
};