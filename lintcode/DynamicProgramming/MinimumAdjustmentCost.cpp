class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        // dp[i][j] means when at length (i+1), minimum cost when changing A[i] to j
        vector<vector<int> > dp(A.size(), vector<int>(101, 0));
        for (int i = 1; i < 101; i++) {
            dp[0][i] = std::abs(A[0] - i);
        }

        for (int i = 1; i < A.size(); i++) {
            for (int j = 1; j < 101; j++) {
                dp[i][j] = INT32_MAX;
                int diff = std::abs(A[i] - j);

                int upper = std::min(100, j + target);
                int lower = std::max(1, j - target);

                for (int k = lower; k <= upper; k++) {
                    dp[i][j] = std::min(dp[i][j], dp[i-1][k] + diff);
                }

            }
        }

        int res = INT32_MAX;
        for (int i = 1; i < 101; i++) {
            res = std::min(res, dp[A.size()-1][i]);
        }
        return res;
    }
};
