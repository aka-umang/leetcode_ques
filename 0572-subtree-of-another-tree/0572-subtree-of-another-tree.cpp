class Solution {
public:
    bool isSameTree(TreeNode* r1, TreeNode* r2){
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL || r2==NULL) return false;
        if(r1->val!=r2->val) return false;
        bool lft=isSameTree(r1->left,r2->left);
        bool rit=isSameTree(r1->right,r2->right);

        return lft && rit;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(root->val==subRoot->val){
            if(isSameTree(root,subRoot)) return true;
        }
        if(isSubtree(root->left,subRoot)) return true;
        if(isSubtree(root->right,subRoot)) return true;
        return false;
    }
};