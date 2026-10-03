class Solution {
public:
    int solve(TreeNode* root,bool dir){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            return (dir)?root->val:0;
        }

        int left=solve(root->left,1);
        int right=solve(root->right,0);
        return left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        //1->left
        //0->right
        return solve(root,0);
    }
};