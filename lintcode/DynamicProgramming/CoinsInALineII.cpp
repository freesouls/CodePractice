class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    /*
    DP[i]表示从i到end能取到的最大value

    当我们走到i时，有两种选择:
    1. 我们取了values[i],对手的选择有 values[i+1]或者values[i+1] + values[i+2] 剩下的最大总value分别为DP[i+2]或DP[i+3], 对手也是理性的所以要让我们得到最小value
    所以 value1 = values[i] + min(DP[i+2], DP[i+3])
    2. 我们取了values[i]和values[i+1] 同理 value2 = values[i] + values[i+1] + min(DP[i+3], DP[i+4])

    最后 DP[I] = max(value1, value2)
    */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        if (n <= 2) {
            return true;
        }
        vector<int> dp(n + 2, 0);
        dp[n-1] = values[n-1];
        dp[n-2] = values[n-1] + values[n-2];
        for (int i = n-3; i >= 0; i--) {
            int v1 = values[i] + min(dp[i+2], dp[i+3]);
            int v2 = values[i] + values[i+1] + min(dp[i+3], dp[i+4]);
            dp[i] = max(v1, v2);
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += values[i];
        }

        return 2*dp[0] > sum;
    }
};
