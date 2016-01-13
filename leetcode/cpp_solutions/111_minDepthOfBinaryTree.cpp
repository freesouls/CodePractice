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
    int min_depth = 0;
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        min_depth = INT_MAX;
        traverse(root, 1);
        return min_depth;
    }
    
    void traverse(TreeNode* root, int depth){
        if (depth >= min_depth) return;
        if (root->left){
            traverse(root->left, depth + 1);
        }
        if (root->right){
            traverse(root->right, depth + 1);
        }
        
        if (root->left == NULL && root->right == NULL && depth < min_depth){
            min_depth = depth;
        }
    }
};