class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;

        TreeNode*l=root->left;
        TreeNode*r=root->right;
        root->left=NULL; root->right=NULL;
        flatten(l);
        flatten(r);

        root->right=l;
        TreeNode*t=root;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=r;
    }
};