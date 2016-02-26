class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */

    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.length();
        int n = B.length();
        if (m == 0 || n == 0) {
            return 0;
        }
        
        if (m > n) {
            return longestCommonSubstring(B, A);
        }
        
        vector<int> dp(m+1, 0);
        int res = 0;
        for (int j = 0; j < n; j++) {
            for (int i = m-1; i >= 0; i--) {
                dp[i+1] = A[i] == B[j] ? dp[i]+1: 0;
                res = std::max(res, dp[i+1]);
            }
        }
        
        return res;
    }
    
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int m = A.length();
        int n = B.length();
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        int res = 0;
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         if (i == 0 || j == 0) {
        //             dp[i][j] = 0;
        //         }
        //         else {
        //             if (A[i-1] == B[j-1]) {
        //                 dp[i][j] = dp[i-1][j-1] + 1;
        //                 res = std::max(res, dp[i][j]);
        //             }
        //             else{
        //                 dp[i][j] = 0;
        //             }
        //         }
        //     }
        // }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i] == B[j]) {
                    dp[i+1][j+1] = dp[i][j]+1;
                    res = std::max(res, dp[i+1][j+1]);
                }
            }
        }
        return res;
    }
};
