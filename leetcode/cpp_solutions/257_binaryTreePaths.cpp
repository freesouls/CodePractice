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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) {
            return res;
        }
        string path = std::to_string(root->val);
        if (root->left || root->right) {
            getPaths(root->left, res, path);
            getPaths(root->right, res, path);
        }
        else{
            res.push_back(path);
        }

        return res;
    }

    void getPaths(TreeNode* root, vector<string>& res, string path){
        if (root == NULL) {
            return ;
        }
        else{
            string tmp = path + "->" + std::to_string(root->val);
            if(root->left == NULL && root->right == NULL){
                res.push_back(tmp);
            }
            else {
                getPaths(root->left, res, tmp);
                getPaths(root->right, res, tmp);
            }
        }
    }
};
