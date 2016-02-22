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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // if (nums.size() == 0) return NULL;
        return build(nums, 0, nums.size()-1);
    }

    TreeNode* build(vector<int>& nums, int left, int right){
        if (left > right) return NULL;
        int index = (left + right)/2;
        //int index = (left + right + 1)/2; will also be OK,
        //the tree build does not have to filled from left to right,
        //satisfy the balanced tree height constraint is OK
        TreeNode* root = new TreeNode(nums[index]);
        root->left = build(nums, left, index - 1);
        root->right = build(nums, index + 1, right);
        return root;
    }
};
