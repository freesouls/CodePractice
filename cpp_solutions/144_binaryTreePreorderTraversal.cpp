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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* pre = NULL, *cur = root;
        while(cur){
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                pre = cur->left;
                while(pre->right && pre->right != cur){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    res.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
    
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (root == NULL) return res;
    //     stack<TreeNode*> s;
    //     TreeNode* node = root;
    //     while(node || !s.empty()){
    //         if (node){
    //             res.push_back(node->val);
    //             s.push(node);
    //             node = node->left;
    //         }
    //         else{
    //             node = s.top();
    //             node = node->right;
    //             s.pop();
    //         }
    //     }
    //     return res;
    // }
    
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (root == NULL) return res;
    //     preorder(root, res);
    //     return res;
    // }
    
    // void preorder(TreeNode* node, vector<int>& res){
    //     res.push_back(node->val);
    //     if (node->left) preorder(node->left, res);
    //     if (node->right) preorder(node->right, res);
    // }
};