/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        max_depth = -1;
        traverse(root, 1);
        return max_depth;
    }
    
    void traverse(TreeNode* root, int depth){
        if (root->left){
            traverse(root->left, depth + 1);
        }
        if (root->right){
            traverse(root->right, depth + 1);
        }
        
        if (root->left == NULL && root->right == NULL && depth > max_depth){
            max_depth = depth;
        }
    }
};