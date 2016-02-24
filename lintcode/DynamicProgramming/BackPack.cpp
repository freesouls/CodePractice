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
