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
    // first one is not rob root, second one is rob root
    // O(N)
    vector<int> robber(TreeNode* root) {
        vector<int> res(2, 0);
        if (!root) {
            return res;
        }

        vector<int> left = robber(root->left);
        vector<int> right = robber(root->right);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
        return res;
    }

    int rob(TreeNode* root) {
        vector<int> res = robber(root);
        return max(res[0], res[1]);
        return max(rob(root, false), rob(root, true));
    }

    // O(N^2)? not sure
    int rob(TreeNode* root, bool use_root) {
        if (!root){
            return 0;
        }

        int left_not_use = rob(root->left, false);
        int right_not_use = rob(root->right, false);

        if (use_root) {

            return left_not_use + right_not_use + root->val;
        }
        else{
            int left_use = rob(root->left, true);
            int right_use = rob(root->right, true);
            return max(left_not_use, left_use) + max(right_not_use, right_use);
        }
    }
};
