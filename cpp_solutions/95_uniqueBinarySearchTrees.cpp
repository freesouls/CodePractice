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
    vector<TreeNode*> generateTrees(int n) 
	{
		return gen(1, n);
	}
	vector<TreeNode*> gen(int left, int right)
	{
		if (left > right) return vector<TreeNode *>(1, nullptr);
		vector<TreeNode *> rs;

		for (int k = left; k <= right; k++)
		{
			vector<TreeNode *> lt = gen(left, k-1);
			vector<TreeNode *> rt = gen(k+1, right);

			for (int i = 0; i < lt.size(); i++)
			{
				for (int j = 0; j < rt.size(); j++)
				{
					TreeNode *n = new TreeNode(k);
					n->left = lt[i];
					n->right = rt[j];
					rs.push_back(n);
				}
			}
		}
		return rs;
	}
};