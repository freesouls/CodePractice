class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    vector<vector<int> > res;
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        res.clear();
        vector<int> path;
        dfs(A, 0, k, target, path);
        return res;
    }

    void dfs(vector<int>& A, int index, int k, int target, vector<int>& path) {
        if (k == 0 && target == 0) {
            res.push_back(path);
        }

        for (int i = index; i < A.size(); i++) {
            if (target-A[i] >= 0) {
                path.push_back(A[i]);
                dfs(A, i+1, k-1, target-A[i], path);
                path.pop_back();
            }
            else {
                break;
            }
        }
    }

};
