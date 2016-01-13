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
    //http://fisherlei.blogspot.jp/2012/12/leetcode-flatten-binary-tree-to-linked.html
    // there is another in-order traverse method in an interview.
    TreeNode* pre = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* right = root->right;
        if (pre != NULL){
            pre->left = NULL;
            pre->right = root;
        }
        pre = root;
        flatten(root->left);
        flatten(right);
    }
    
};