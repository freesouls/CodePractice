/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int max_sum = INT32_MIN;
        getMaxSum(root, &max_sum);
        return max_sum;
    }

    int getMaxSum(TreeNode *root, int * max_sum) {
        if (!root) {
            return 0;
        }

        int left = getMaxSum(root->left, max_sum);
        int right = getMaxSum(root->right, max_sum);
        if (*max_sum < (left + right + root->val)) {
            *max_sum = left + right + root->val;
        }

        return max(max(max(left, right) + root->val, root->val), 0);
    }
};
