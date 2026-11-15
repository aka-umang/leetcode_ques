class Solution {
public:
    typedef long long LL;
    int m,n;

    long long solve(vector<vector<int>>& points){
        vector<LL> prevRow(n); 
        vector<LL> currRow(n);
        for(int c=0;c<n;c++) prevRow[c]=points[0][c];

        for(int r=1;r<m;r++){
            vector<LL>prevR(n); prevR[n-1]=prevRow[n-1];
            vector<LL>prevL(n); prevL[0]=prevRow[0];

            for(int c=n-2;c>=0;c--){
                prevR[c] = max(prevR[c+1] - 1, prevRow[c]);
            }

            for(int c=1;c<n;c++){
                prevL[c] = max(prevL[c-1] - 1, prevRow[c]);
            }

            for(int c=0;c<n;c++){
                currRow[c]=points[r][c]+max(prevR[c],prevL[c]);
            }

            swap(prevRow,currRow);
        }

        LL ans=0;
        for(int c=0;c<n;c++){
            ans=max(ans,prevRow[c]);
        }
        return ans;
    }

    long long maxPoints(vector<vector<int>>& points) {
        m=points.size();
        n=points[0].size();

        return solve(points);
    }
};