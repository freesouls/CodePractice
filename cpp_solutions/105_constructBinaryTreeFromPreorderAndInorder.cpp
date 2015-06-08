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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int p_s, int p_e, int i_s, int i_e){
        if (p_s > p_e || i_s > i_e) return NULL;
        int root_val = preorder[p_s];
        int index = findRoot(inorder, root_val, i_s, i_e);
        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, inorder, p_s + 1, p_s + index - i_s, i_s, index - 1);
        root->right = build(preorder, inorder, p_s + (index - i_s) + 1 , p_e, index + 1, i_e);
        return root;
    }
    
    int findRoot(vector<int>& inorder, int val, int start, int end){
        for (int i=start; i <= end; i++){
            if (inorder[i] == val){
                return i;
            }
        }
    }
};