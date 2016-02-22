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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int left_height = getHeight(root, 1);
        int right_height = getHeight(root, 0);
        if (left_height == right_height){
            return pow(2, left_height) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int getHeight(TreeNode* root, int direction){
        int max_height = 0;
        if (direction){
            while(root){
                max_height++;
                root = root->left;
            }
        }else{
            while(root){
                max_height++;
                root = root->right;
            }
        }
        return max_height;
    }

};

class Solution {
public:    
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = 0;
        TreeNode* node = root;
        while(node->left) {
           left++;
           node = node->left;
        }

        int right = 0;
        node = root;
        while(node->right) {
           right++;
           node = node->right;
        }

        if (left == right) {
           return pow(2, left+1) - 1;
        }
        else {
           return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
