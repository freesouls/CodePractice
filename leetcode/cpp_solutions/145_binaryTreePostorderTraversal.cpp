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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(cur != NULL || !st.empty()) {
            while (cur) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }
            TreeNode* node = st.top();
            st.pop();
            cur = node->left;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    // change left and right in the preorder version, and finally reverse the vector
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* pre = NULL, *cur = root;
        while(cur){
            if(cur->right == NULL){
                res.push_back(cur->val);
                cur = cur->left;
            }
            else{
                pre = cur->right;
                while(pre->left && pre->left != cur){
                    pre = pre->left;
                }
                if(pre->left == NULL){
                    res.push_back(cur->val);
                    pre->left = cur;
                    cur = cur->right;
                }
                else{
                    pre->left = NULL;
                    cur = cur->left;
                }
            }
        }
        std::reverse(res.begin(), res.end()); // it cost time, so use next version
        return res;
    }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (root == NULL) return res;
    //     TreeNode* pre = NULL, *node = root;
    //     stack<TreeNode*> s;
    //     while(node || !s.empty()){
    //         if(node){
    //             s.push(node);
    //             node = node->left;
    //         }
    //         else{
    //             TreeNode* sTop = s.top();
    //             if (sTop->right && sTop->right != pre){
    //                 node = sTop->right;
    //             }
    //             else{
    //                 res.push_back(sTop->val);
    //                 s.pop();
    //                 pre = sTop;
    //             }
    //         }
    //     }
    //     return res;
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (root == NULL) return res;
    //     postorder(root, res);
    //     return res;
    // }

    // void postorder(TreeNode* node, vector<int>& res){
    //     if (node->left) postorder(node->left, res);
    //     if (node->right) postorder(node->right, res);
    //     res.push_back(node->val);
    // }
};
