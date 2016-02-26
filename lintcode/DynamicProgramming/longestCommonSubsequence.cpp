class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        
        int m = A.length();
        int n = B.length();
        
        if (m > n) {
            return longestCommonSubsequence(B, A);
        }

        if (m == 0) {
            return 0;
        }
        
        vector<int> dp(m+1, 0);

        for (int j = 0; j <= n; j++) {
            int prev = 0;
            for (int i = 0; i <= m; i++) {
                int tmp = dp[i];
                if (i == 0) {
                    dp[i] = 0;
                }
                else {
                    if (A[i-1] == B[j-1]) {
                        //dp[i][j] = 1 + dp[i-1][j-1];
                        dp[i] = 1 + prev;
                    }
                    else {
                        //dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                        dp[i] = std::max(dp[i-1], dp[i]);
                    }
                }
                prev = tmp;
            }
        }
        return dp[m];
    }

    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m = A.length();
        int n = B.length();
        
        if (m > n) {
            return longestCommonSubsequence(B, A);
        }
        
        if (m == 0) {
            return 0;
        }

        vector<int> dp(m+1, 0);
        vector<int> dp_prev(m+1, 0);
        
        for (int j = 0; j < n; j++) {
            int prev = 0;
            for (int i = 0; i < m; i++) {
                prev = dp[i];
                dp[i+1] = A[i] == B[j] ? 1 + dp_prev[i]: std::max(dp_prev[i+1], dp[i]);
                // dp[i+1][j+1] = A[i]==B[j]? 1+dp[i][j] : std::max(dp[i+1][j], dp[i][j+1]);
            }
            dp_prev = dp;
        }
        return dp[m];
    }

    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m = A.length();
        int n = B.length();
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                dp[i+1][j+1] = A[i]==B[j]? 1+dp[i][j] : std::max(dp[i+1][j], dp[i][j+1]);
                
            }
        }
        return dp[m][n];
    }

};
