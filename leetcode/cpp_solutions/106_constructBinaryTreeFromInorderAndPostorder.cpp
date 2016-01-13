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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;
        
        return build(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int p_s, int p_e, int i_s, int i_e){
        if (p_s > p_e || i_s > i_e) return NULL;
        int root_val = postorder[p_e];
        int index = findRoot(inorder, root_val, i_s, i_e);
        TreeNode* root = new TreeNode(root_val);
        root->left = build(postorder, inorder, p_s, p_s + index - i_s - 1, i_s, index - 1);
        root->right = build(postorder, inorder, p_e - (i_e - index) , p_e - 1, index + 1, i_e);
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