
class Solution {
public:
    // the key is use dynamic programming, start from 1 to amount
    // for each number get its min coins count
    // what's more, we do not have to worry about whether coins is sorted or not
    // actually when amount is large, the dp requires really much memory
    // for real large amount, use unordered_map? though hashing & finding need time, but it requires less memory
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i ++){
            for(int j = 0; j < n; j ++){
                // get min coins when amount = i
                if(i - coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
