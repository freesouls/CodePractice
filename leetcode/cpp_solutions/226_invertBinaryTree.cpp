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
    TreeNode* invertTree(TreeNode* root) {
        non_recursive_invert(root);
        //invert(root);
        return root;
    }
    
    void non_recursive_invert(TreeNode* root) {
        queue<TreeNode* > s;
        TreeNode* node = root;
        if (root) s.push(root);
        
        while(!s.empty()){
            TreeNode* node = s.front();
            s.pop();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
    }
    
    void invert(TreeNode* root){
        if (root){
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invert(root->left);
            invert(root->right);
        }
    }
};