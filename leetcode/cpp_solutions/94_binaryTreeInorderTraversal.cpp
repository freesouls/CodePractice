/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(cur != NULL || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            cur = node->right;
        }
        return res;
    }
};

class Solution {
public:
    //http://blog.csdn.net/linhuanmars/article/details/20187257
    //Morris, or threaded traversal
    vector<int> inorderTraversal(TreeNode* root) {
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
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }

    // version 1
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (root == NULL) return res;
    //     inorder(root, res);
    //     return res;
    // }
    // void inorder(TreeNode* node, vector<int>& res){
    //     if (node->left) inorder(node->left, res);
    //     res.push_back(node->val);
    //     if (node->right) inorder(node->right, res);
    // }

    // version 2
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (root == NULL) return res;
    //     stack<TreeNode*> s;

    //     TreeNode* node = root;
    //     while(node || !s.empty() ){
    //         if (node != NULL){
    //             s.push(node);
    //             node = node->left;
    //         }
    //         else{
    //             node = s.top();
    //             res.push_back(node->val);
    //             s.pop();
    //             node = node->right;
    //         }
    //     }
    //     return res;
    // }
};
