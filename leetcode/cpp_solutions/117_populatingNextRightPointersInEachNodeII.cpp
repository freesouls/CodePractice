/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;

        TreeLinkNode* dummy = new TreeLinkNode(0);
        TreeLinkNode* prev = dummy;
        while(root){
            if (root->left){
                prev->next = root->left;
                prev = prev->next;
            }

            if (root->right){
                prev->next = root->right;
                prev = prev->next;
            }
            root = root->next;
        }
        connect(dummy->next);
    }

    void connect1(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* prev = NULL;
        TreeLinkNode* next = NULL;
        while(root){

            if (!next) next = root->left ? root->left: root->right;
            if (root->left){
                if (prev){
                    prev->next = root->left;
                }
                prev = root->left;
            }

            if (root->right){
                if (prev){
                    prev->next = root->right;
                }
                prev = root->right;
            }
            root = root->next;
        }
        connect(next);
    }

    void connect2(TreeLinkNode *root) {
        while(root){
            TreeLinkNode* prev = NULL;
            TreeLinkNode* next = NULL;
            while(root){
                if (!next) next = root->left ? root->left: root->right;
                if (root->left){
                    if (prev){
                        prev->next = root->left;
                    }
                    prev = root->left;
                }

                if (root->right){
                    if (prev){
                        prev->next = root->right;
                    }
                    prev = root->right;
                }
                root = root->next;
            }
            root = next;
        }
    }
};

// the same as above
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root) {
            TreeLinkNode* prev = NULL;
            TreeLinkNode* next_level_start = NULL;
            while(root){
                if (root->left) {
                    if (!next_level_start){
                        next_level_start = root->left;
                    }
                    if (prev) {
                        prev->next = root->left;
                    }
                    prev = root->left;
                }

                if (root->right) {
                    if(!next_level_start) {
                        next_level_start = root->right;
                    }
                    if (prev) {
                        prev->next = root->right;
                    }
                    prev = root->right;
                }

                root = root->next;
            }
            root = next_level_start;
        }
    }
};
