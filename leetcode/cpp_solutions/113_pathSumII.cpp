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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        vector<int> tmp;
        pathSum(root, sum, tmp, res);
        return res;
    }
    
    void pathSum(TreeNode* root, int sum, vector<int> tmp, vector<vector<int> > &res){
        tmp.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum == root->val){
            res.push_back(tmp);
        }
        if (root->left)
            pathSum(root->left, sum-root->val, tmp, res);
        if (root->right)
            pathSum(root->right, sum-root->val, tmp, res);
    }
};