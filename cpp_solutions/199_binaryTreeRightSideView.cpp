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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL){
            return res;
        }
        deque<TreeNode *> Q;
        Q.push_back(root);
        int count = 1;
        while(!Q.empty()){
            res.push_back(Q.back()->val);
            int nextCount = 0; // cal next row count
            for(int i = 0; i < count; i++){     // one row count
                TreeNode *tmp = Q.front();
                Q.pop_front();
                if(tmp->left){
                    Q.push_back(tmp->left);
                    nextCount++;
                }
                if(tmp->right){
                    Q.push_back(tmp->right);
                    nextCount++;
                }
            }
            count = nextCount;
        }
        return res;
    }
};