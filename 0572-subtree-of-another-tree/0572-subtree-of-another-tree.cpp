class Solution {
public:
    string work(TreeNode* root){
        if(root==NULL) return "#";
        string lft=work(root->left);
        string ri8=work(root->right);
        return to_string(root->val)+"_"+lft+"_"+ri8;
    }

    string find(TreeNode* root,string& target){
        if(root==NULL) return "#";
        string lft=find(root->left, target); if(lft=="milgya") return lft;
        string ri8=find(root->right, target); if(ri8=="milgya") return ri8;

        string curr=to_string(root->val)+"_"+lft+"_"+ri8;
        if(curr==target) return "milgya";
        return curr;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str_subroot=work(subRoot);

        if(find(root,str_subroot)=="milgya") return true;
        return false;
    }
};