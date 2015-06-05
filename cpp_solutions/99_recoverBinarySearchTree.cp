class Solution {
public:
    
    TreeNode* s1 = NULL, *s2 = NULL;
    TreeNode* pre = NULL;
    void recoverTree(TreeNode* root) {
        traverse(root);
        if (s1 == NULL && s2 == NULL){
            return;
        }
        else{
            int tmp = s1->val;
            s1->val = s2->val;
            s2->val = tmp;
        }
    }
    
    void traverse(TreeNode* root){
        if (root != NULL){
            if (root->left != NULL) traverse(root->left);
            if (pre != NULL && root->val < pre->val){
                if (s1 == NULL){
                    s1 = pre;
                }
                s2 = root;
            }
            pre = root;
            if(root->right != NULL) traverse(root->right);
            
        }
    }
    
};