// http://blog.csdn.net/abcbc/article/details/8978146
class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if (T.length() > S.length()) {
            return 0;
        }
        vector<int> dp(T.length()+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= S.length(); i++) {
            for (int j = T.length(); j >= 1; j--) {
                dp[j] = dp[j] + (S[i-1] == T[j-1] ? dp[j-1]: 0);
            }
        }
        return dp[T.length()];
    }

    int numDistinct2(string &S, string &T) {
        // write your code here
        if (T.length() > S.length()) {
            return 0;
        }
        vector<vector<int> > dp(S.length()+1, vector<int>(T.length()+1, 0));
        for (int i = 0; i <= S.length(); i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= T.length(); j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= S.length(); i++) {
            for (int j = 1; j <= T.length(); j++) {
                dp[i][j] = dp[i-1][j] + (S[i-1] == T[j-1] ? dp[i-1][j-1]: 0);
            }
        }
        return dp[S.length()][T.length()];
    }
};
