class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if (root == NULL) return true;
    	return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* t1, TreeNode* t2){
    	if (t1== NULL && t2 != NULL) return false;
    	if (t1 != NULL && t2 == NULL) return false;
    	if (t1 == NULL && t2 == NULL) return true;
    
    	if (t1->val != t2->val){
    		return false;
    	}
    	return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
    }
};