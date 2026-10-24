class Solution {
public:
    TreeNode* solve(vector<int>& pre, vector<int>& in, int start, int end, int &idx){
        if(start>end) return NULL;
        TreeNode* root=new TreeNode(pre[idx]);

        int i=start;
        for(;i<=end;i++){
            if(in[i]==pre[idx]){
                break;
            }
        }
        idx++;
        root->left=solve(pre,in,start,i-1,idx);
        root->right=solve(pre,in,i+1,end,idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        int n=inorder.size();
        return solve(preorder,inorder,0,n-1,idx);
    }
};