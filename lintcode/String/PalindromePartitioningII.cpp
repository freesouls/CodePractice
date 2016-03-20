// https://leetcode.com/discuss/9476/solution-does-not-need-table-palindrome-right-uses-only-space
/*
This divide-and-conquer algorithm utilize the symmetry of palindromes, so there is no need to cache the result of whether s[i:j) is a palindrome.

Say that it started at s[i] = 'b', and s[i-1,i+1] is a palindrome "aba":

.......aba...
|<-X->| ^
|<---Y-->|
And we know the least cuts for s[0,i-1) is X, then the least cuts for s[0,i+1] Y is not greater than X+1. Last, we need to find out all the palindromes in s[0,i+1] so as to minimize the number of cuts.
*/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */

    int minCut(string s) {
        // write your code here
        if (s.length() == 0){
            return 0;
        }
        int len = s.length();
        // cuts[i]: means mincut in string[i:len-1]
        // cuts[len-1] = 0 is because str[len-1:len-1] is palindrome
        // cuts[0] = len - 1, we assume it is the worst case
        int cuts[len + 1];
        for(int i = 0; i <= len; i++){
            cuts[i] = len - i - 1;
        }
        // p[i][j] = true if string[i:j] is palindrome
        vector<vector<bool>> p(len, vector<bool>(len, false));

        for (int i = len - 1; i >= 0; i--){
            for (int j = i; j < len; j++){
                if (s[i]==s[j] && (j - i < 2 || p[i+1][j-1])){
                    p[i][j] = true;
                    // cuts[i] = min(cuts[i], cuts[i:j] + cuts[j:len-1])
                    // cust[i:j] = 1 because p[i][j] is true
                    cuts[i] = min(cuts[i], 1 + cuts[j + 1]);
                }
            }
        }
        return cuts[0];
    }
};

class Solution {
public:
    /*
    整体的思路是一维DP。DP[i]表示长度为i的prefix：s[0: i-1]的min cut数量。
    DP[i] = min (DP[j] + 1) ，对所有 0<=j<i，且s[j: i-1]为palindrome。
    和I同样的技巧，用DP先计算存储一个palindrome判断矩阵isPal[i][j]，便于后面一维DP计算中能迅速判断s[j: i-1]是否为palindrome。
    */
    int minCut(string s) {
        int n = s.size();
        if(n<=1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j])
                    isPal[i][j] = true;
            }
        }

        vector<int> dp(n+1,INT_MAX);
        dp[0] = -1;
        for(int i=1; i<=n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(isPal[j][i-1]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};
