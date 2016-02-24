class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        // vector<vector<int> > dp(m+1, vector<int>(m+1, 0));
        vector<int> dp(m+1, 0);
        for (int i = 0; i < A.size(); i++) {
            for (int j = m; j >= A[i]; j--) {
                // if (j >= A[i]) {
                    dp[j] = std::max(dp[j], dp[j-A[i]] + A[i]);
                // }
            }
        }
        return dp[m];
    }
};

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        vector<vector<int> > dp(A.size()+1, vector<int>(m+1, 0));

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < std::min(A[i], m+1); j++) {
                dp[i+1][j] = dp[i][j];
            }
            for (int j = A[i]; j <= m; j++) {
                dp[i+1][j] = std::max(dp[i][j], dp[i][j-A[i]] + A[i]);
            }
        }
        return dp[A.size()][m];
    }
};
