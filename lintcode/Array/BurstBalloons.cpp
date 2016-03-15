class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */
    int maxCoins(vector<int>& nums) {
        // Write your code here
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

        for (int len = 1; len <= n; len++) {
            for (int start = 1; start + len - 1 <= n; start++) {
                int end = start + len - 1;
                int max_in_range = 0;
                for (int i = start; i <= end; i++) {
                    int tmp = dp[start][i-1]
                            + nums[start-1]*nums[i]*nums[end+1]
                            + dp[i+1][end];

                    max_in_range = max(max_in_range, tmp);
                }

                dp[start][end] = max_in_range;
            }
        }

        return dp[1][n];
    }
};
