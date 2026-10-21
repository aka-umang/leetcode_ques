class Solution {
public:
    int work(TreeNode* root, int& ans){
        if(root==NULL) return 1;

        int l=work(root->left,ans);
        int r=work(root->right,ans);

        if(l==-1 || r==-1){
            ans++;
            return 0;
        }
        else if(l==0 || r==0) return 1;
        else return -1;
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
       
        if(work(root,ans)==-1) return ans+1;
        return ans;
    }
};