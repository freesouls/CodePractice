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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return generate(1, n);
    }

    vector<TreeNode *> generate(int left, int right) {
        if (left > right) {
            return vector<TreeNode*>(1, NULL);
        }

        vector<TreeNode*> res;

        for (int i = left; i <= right; i++) {
            vector<TreeNode*> lefts = generate(left, i-1);
            vector<TreeNode*> rights = generate(i+1, right);
            for (int j = 0; j < lefts.size(); j++) {
                for (int k = 0; k < rights.size(); k++) {
                    TreeNode * root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
