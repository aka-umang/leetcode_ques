class Solution {
public:
    unordered_map<string,int>mp;
    
    string solve(TreeNode* root, vector<TreeNode*>&ans){
        if(root==NULL) return "#";
        string left=solve(root->left,ans);
        string right=solve(root->right,ans);

        string s=to_string(root->val)+","+left+","+right;
        if(mp[s]==1){
            ans.push_back(root);
        }
        mp[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;

        solve(root,ans);
        return ans;
    }
};