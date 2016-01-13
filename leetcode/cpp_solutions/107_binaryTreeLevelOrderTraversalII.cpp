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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL){
            return res;
        }
        
        levelOrder(root, 1, res);
        std::reverse(res.begin(), res.end());
        return res;
    }
    
    void levelOrder(TreeNode* node, int depth, vector<vector<int> > &res){
        if (res.size() < depth){
            vector<int> tmp;
            res.push_back(tmp);
            res[depth-1].push_back(node->val);
        }
        else{
            res[depth-1].push_back(node->val);
        }
        if (node->left) levelOrder(node->left, depth+1, res);
        if (node->right) levelOrder(node->right, depth+1, res);
    }
};