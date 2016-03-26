/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (abs(getHeight(root->left) - getHeight(root->right))>1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getHeight(TreeNode* root){
        if (root == NULL) {
            return 0;
        }
        else {
            return 1+std::max(getHeight(root->left), getHeight(root->right));
        }
    }
};
