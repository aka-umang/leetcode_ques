class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode*par1=NULL;
        TreeNode*par2=NULL;
        queue<TreeNode* >que; que.push(root);
        
        while(!que.empty()){
            int n=que.size();
            while(n--){
                TreeNode* t=que.front(); que.pop();         
                if(t->left){
                    que.push(t->left);
                    if(t->left->val==x || t->left->val==y){
                        if(par1==NULL) par1=t;
                        else par2=t;
                    }
                }

                if(t->right){
                    que.push(t->right);
                    if(t->right->val==y || t->right->val==x){
                        if(par1==NULL) par1=t;
                        else par2=t;
                    } 
                }
            }
                if(par1 || par2)   return (par1!=par2 && par1 && par2);
            }

        return false;
    }
};