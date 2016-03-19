class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */

    /*
    dp(n) = same(n) + diff(n);
    same(n): means n has the same color as n-1
    diff(n): means n has different color as n-1
    same(n) = diff(n-1), because no more than two adjacent fence have the same color,
            n-1, n-2 is different, than n-1 and n can be the same
    diff(n) = dp(n-1)*(k-1)
    dp(n) = same(n) + diff(n) = diff(n-1) + diff(n) = dp(n-2)*(k-1) + dp(n-1)*(k-1)
          = (k-1)(dp(n-1) + dp(n-2))
    */

    int numWays(int n, int k) {
        // Write your code here
        if (n <= 0 || k <= 0) {
            return 0;
        }

        if (n == 1) {
            return k;
        }
        vector<int> dp(n+1, 0);
        dp[1] = k;
        dp[2] = k*k;

        for (int i = 3; i <= n; i++) {
            dp[i] = (k-1)*(dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};
