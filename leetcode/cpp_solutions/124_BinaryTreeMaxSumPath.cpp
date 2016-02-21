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
     int max_sum = 0;
     int maxPathSum(TreeNode* root) {
         max_sum = INT32_MIN;
         dfs(root);
         return max_sum;
     }
     
     int dfs(TreeNode* root) {
         if (root == NULL) {
             return 0;
         }

         int left_max = dfs(root->left);
         int right_max = dfs(root->right);
         int sum = root->val;
         if (left_max > 0) {
             sum += left_max;
         }

         if (right_max > 0) {
             sum += right_max;
         }

         max_sum = std::max(max_sum, sum);

         return std::max(left_max, right_max) > 0? std::max(left_max, right_max) + root->val: root->val;
     }
 };
