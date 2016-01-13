/**
 * Definition for a binary tree node->
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right==NULL && root->val==sum)
            return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
    /*
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        return hasPathSum(root, sum, root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum, int cur){
        if (root->left == NULL && root->right == NULL) {
            if (sum == cur) 
                return true;
            else
                return false;
        }
        else{
            bool flag = false;
            if (root->left) 
                flag = hasPathSum(root->left, sum, cur + root->left->val);
            if (!flag && root->right)
                flag = hasPathSum(root->right, sum, cur + root->right->val);
            return flag;
        }
    }
    */
};