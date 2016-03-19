class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        vector<int> dp(n+1, 0);

        for (int i = 1; i <= n; i++) {
            int tmp = INT32_MAX;
            for (int j = 1; j*j <= i; j++) {
                tmp = std::min(tmp, dp[i-j*j]+1);
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};
