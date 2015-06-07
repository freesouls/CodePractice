class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root != NULL){
            if (root->left != NULL) root->left->next = root->right;
            if (root->right != NULL) root->right->next = root->next ? root->next->left:NULL ;
            connect(root->left);
            connect(root->right);
        }
    }
};