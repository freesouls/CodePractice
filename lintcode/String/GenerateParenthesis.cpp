class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> res;
        if (n <= 0) {
            return res;
        }
        dfs(res, n, n, "");
        return res;
    }

    void dfs(vector<string> &res, int left, int right, string str) {
        if (left == 0 && right == 0) {
            res.push_back(str);
        }

        if (left > 0) {
            dfs(res, left-1, right, str + "(");
        }

        if (right > left) { // it can gurantee right will > 0
            dfs(res, left, right-1, str + ")");
        }
    }
};
