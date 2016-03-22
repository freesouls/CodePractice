class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    /*
    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1
    */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int res = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 1 + std::min(std::min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
                    res = std::max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};
