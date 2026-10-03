class Solution {
public:   
    void width(TreeNode* root,int p,int& mini, int& maxi){
        if(root==NULL) return;
        
        width(root->left,p-1,mini,maxi);
        width(root->right,p+1,mini,maxi);
        mini=min(mini,p);
        maxi=max(maxi,p);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        width(root,0,mini,maxi);
        vector<vector<int>>ans(maxi-mini+1);

        vector<pair<TreeNode*,int>>que;
        que.push_back({root,abs(mini)});

        auto cmp=[&](pair<TreeNode*,int> &v1, pair<TreeNode*,int> &v2){
            return v1.first->val<v2.first->val;
        };

        while(que.size()>0){
            int n=que.size();
            vector<pair<TreeNode*,int>>temp;
            while(n--){
                auto [t,v]=que.back();
                temp.push_back({t,v});
                que.pop_back();
            }
            sort(temp.begin(),temp.end(),cmp);
            for(auto& [t,v]:temp){
                ans[v].push_back(t->val);

                if(t->left) que.push_back({t->left,v-1});
                if(t->right) que.push_back({t->right,v+1});
            }
        }

        return ans;
    }
};