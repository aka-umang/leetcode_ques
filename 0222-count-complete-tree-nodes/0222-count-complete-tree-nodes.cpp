class Solution {
public:
    int HMost(TreeNode*root, bool d){
        int h=0;
        while(root){
            ++h;
            if(d==true) root=root->left; //left
            else root=root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int l=HMost(root,true);
        int r=HMost(root,false);
        if(l==r){
            return (1<<l)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};