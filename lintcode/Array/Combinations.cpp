class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > res;
        vector<int> path;

        dfs(res, path, 1, k, n);
        return res;
    }

    void dfs(vector<vector<int> >& res, vector<int> & path, int index, int k, int n) {
        if (path.size() >= k) {
            if (path.size() == k) {
                res.push_back(path);
            }
            return;
        }

        for(int i = index; i <= n; i++) {
            path.push_back(i);
            dfs(res, path, i + 1, k, n);
            path.pop_back();
        }
    }

};
