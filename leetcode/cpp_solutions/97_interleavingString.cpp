class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int p = s3.length();
        if(m + n != p) {
            return false;
        }

        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int i = 1; i < m + 1; i++) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        for (int j = 1; j < n + 1; j++) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        return dp[m][n];
    }
};


// one-way dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m > n) return isInterleave(s2, s1, s3);
        if (l != m + n) return false;
        bool *dp = new bool[m + 1]();
        dp[0] = true;
        for (int i = 1; i <= m; i++)
            dp[i] = dp[i - 1] && s3[i - 1] == s1[i - 1];
        for (int j = 1; j <= n; j++) {
            dp[0] = dp[0] && s3[j - 1] == s2[j - 1];
            for (int i = 1; i <= m; i++)
                dp[i] = (dp[i - 1] && s3[i + j - 1] == s1[i - 1]) || (dp[i] && s3[i + j - 1] == s2[j - 1]);
        }
        return dp[m];
    }
};

// TLE
class Solution {
    string ss1;
    string ss2;
    string ss3;
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) {
            return false;
        }
        ss1 = s1;
        ss2 = s2;
        ss3 = s3;

        return isIterleave(0, 0, 0);
    }

    bool isIterleave(int i, int j, int k) {
        if (k == ss3.length()) {
            return true;
        }

        if (i < ss1.length() && j < ss2.length()) {
            if (ss1[i] == ss3[k]) {
                if (isIterleave(i+1, j, k+1)) {
                    return true;
                }
            }

            if (ss2[j] == ss3[k]) {
                if (isIterleave(i, j+1, k+1)) {
                    return true;
                }
            }
            return false;
        }

        if (i < ss1.length()) {
            if (ss1[i] == ss3[k]) {
                if (isIterleave(i+1, j, k+1)) {
                    return true;
                }
            }
            return false;
        }

        if (j < ss2.length()) {
            if (ss2[i] == ss3[k]) {
                if (isIterleave(i, j+1, k+1)) {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
};
