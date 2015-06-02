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
    /* // much faster, but harder to understand, http://blog.csdn.net/ljiabin/article/details/41699241
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        
        if (root){
            if(!isValidBST(root->left))
                return false;
            if (prev != NULL && root->val <= prev->val)
                return false;
                
            prev = root;
            
            return isValidBST(root->right);
        }
        return true;
    }
    */
    vector<int> arr;
    bool isValidBST(TreeNode* root){
        if (root == NULL)
            return true;
        arr.clear();
        inOrderTraverse(root);
        if (arr.size() == 1) return true;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] >= arr[i+1]) return false;
        }
        return true;
    }
    
    void inOrderTraverse(TreeNode* root){
        if(root->left)
            inOrderTraverse(root->left);
        arr.push_back(root->val);
        if(root->right)
            inOrderTraverse(root->right);
    }
    
};