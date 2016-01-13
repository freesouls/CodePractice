/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    int cnt = 0;
    int num = -1;
    int target;
    int flag = true;
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        flag = true;
        inorder(root);
        return num;
    }
    void inorder(TreeNode* node){
        if (flag && node->left) inorder(node->left);
        cnt++;
        if(cnt == target){
            num = node->val;
            flag = false;
            // return ;
        }
        // res.push_back(node->val);
        if (flag && node->right) inorder(node->right);
    }
};
*/
class Solution {
public:
    int cnt = 0;
    int num = -1;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return num;
    }
    void inorder(TreeNode* node, int k){
        if (node->left) inorder(node->left, k);
        cnt++;
        if(cnt == k){
            num = node->val;
            return ;
        }
        // res.push_back(node->val);
        if (node->right) inorder(node->right, k);
    }
};
