class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int u=intervals[0][0];
        int v=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int x=intervals[i][0];
            int y=intervals[i][1];
            if(v>=x){
                v=max(v,y);
            }
            else {
                ans.push_back({u,v});
                u=x;
                v=y;
            }
        }
        ans.push_back({u,v});
        return ans;
    }
};