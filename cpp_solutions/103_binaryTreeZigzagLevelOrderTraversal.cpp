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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL){
            return res;
        }
        //version 2
        queue<TreeNode *> Q;
        Q.push(root);
        int count = 1;
        while(!Q.empty()){
            vector<int> vec;
            int nextCount = 0;      // cal next row count
            for(int i = 0; i < count; i++){     // one row count
                TreeNode *tmp = Q.front();
                Q.pop();
                vec.push_back(tmp->val);        // save one row val
                if(tmp->left){
                    Q.push(tmp->left);
                    nextCount++;
                }
                if(tmp->right){
                    Q.push(tmp->right);
                    nextCount++;
                }
            }
            count = nextCount;
            res.push_back(vec);
        }
        for(int i=1; i < res.size(); i=i+2){
            std::reverse(res[i].begin(), res[i].end());
        }
        //levelOrder(root, 1, res);
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