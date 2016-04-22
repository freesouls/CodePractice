// https://leetcode.com/discuss/98173/o-log-n-time-solution-with-explanation
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n-1;
        }

        int a = n/3;
        int b = n%3;
        int res = pow(3, a-1);
        if (b == 0) {
            return 3*res;
        }
        else if (b == 1) {
            return 4*res;
        }
        else {
            return 6*res;
        }
    }
};

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i ++) {
            for(int j = 1; 2*j <= i; j ++) {
                dp[i] = max(dp[i], (max(j,dp[j])) * (max(i - j, dp[i - j])));
            }
        }
        return dp[n];
    }
};
