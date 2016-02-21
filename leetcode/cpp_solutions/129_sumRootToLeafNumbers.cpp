class Solution {
public:
    int sum = 0;

    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int num) {
        if (root == NULL) {
            return;
        }

        num = num*10 + root->val;
        if (root->left == NULL && root->right == NULL){
            sum += num;
            return;
        }

        dfs(root->left, num);
        dfs(root->right, num);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        vector<int> num;
        traverse(root, 0, num);
        int sum = 0;
        for (int i=0; i < num.size(); i++){
            sum += num[i];
        }
        return sum;
    }

    void traverse(TreeNode* t, int sum, vector<int> &num){
        int tmp = sum*10 + t->val;

        if (t->left != NULL) traverse(t->left, tmp, num);
        if (t->right != NULL) traverse(t->right, tmp, num);
        if (t->left == NULL && t->right == NULL) num.push_back(tmp);
    }

};
