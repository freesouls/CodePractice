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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        search(root, k1, k2, res);
        return res;
    }

    void search(TreeNode* root, int k1, int k2, vector<int>& res) {
        if (root){
            if (root->val >= k1) {
                search(root->left, k1, k2, res);
            }
            if (root->val <= k2 && root->val >= k1) {
                res.push_back(root->val);
            }
            search(root->right, k1, k2, res);
        }
    }
};
