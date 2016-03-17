// http://www.cnblogs.com/yuzhangcmu/p/4279676.html
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */

    int kSum(vector<int> A, int k, int target) {
        vector<vector<vector<int>>> sols(A.size() + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));

        for (int i = 0; i <= A.size(); i++) {
            for (int j = 0; j <= k; j++) {
                for (int t = 0; t <= target; t++) {
                    if (j == 0 && t == 0) {
                        sols[i][j][t] = 1;
                    }
                    else if(!(i == 0 || j == 0 || t == 0)){
                        sols[i][j][t] = sols[i-1][j][t];
                        if (t - A[i-1] >= 0) {
                            sols[i][j][t] += sols[i-1][j-1][t-A[i-1]];
                        }
                    }
                }
            }
        }

        return sols[A.size()][k][target];
    }

    int cnt = 0;
    int kSum2(vector<int> A, int k, int target) {
        // wirte your code here
        sort(A.begin(), A.end());
        cnt = 0;

        dfs(A, 0, k, target);
        return cnt;
    }

    void dfs(vector<int>& A, int index, int k, int target) {
        if (k == 0 && target == 0) {
            cnt++;
        }

        for (int i = index; i < A.size(); i++) {
            if (target-A[i] >= 0) {
                dfs(A, i+1, k-1, target-A[i]);
            }
            else {
                break;
            }
        }
    }
};
