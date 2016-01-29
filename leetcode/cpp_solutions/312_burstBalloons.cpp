class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int> > max_in_range(n + 2, vector<int>(n + 2, 0));

        // start from length = 1 to length = n
        for (int len = 1; len <= n; len++) {
            for (int start = 1; start + len - 1 <= n; start++) {
                int end = start + len - 1;

                int max_coin = 0;
                for (int i = start; i <= end; i++) {
                    int left_right = max_in_range[start][i-1] + max_in_range[i+1][end];
                    max_coin = std::max(left_right + nums[start-1]*nums[i]*nums[end+1], max_coin);
                }
                max_in_range[start][end] = max_coin;
            }
        }
        return max_in_range[1][n];

    }

};

// divide and conquer: TLE
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return getMax(nums, 1, nums.size() - 1);
    }

    int getMax(vector<int>& nums, int start, int end) {
        if (start > end) {
            return 0;
        }

        if (end - start == 0) {
            // int left = nums[start-1];
            // int right = nums[end+1];
            // int left = start - 1 < 0 ? 1:nums[start-1];
            // int right = end + 1 < nums.size() ? nums[end+1]: 1;
            // return left*nums[start]*right;
            return nums[start-1]*nums[start]*nums[end+1];
        }

        int cur_max = 0;
        for (int i = start; i <= end; i++) {
            int left = getMax(nums, start, i - 1);
            int right = getMax(nums, i + 1, end);
            cur_max = std::max(left+right+nums[start-1]*nums[i]*nums[end+1], cur_max);
        }
        return cur_max;
    }
};
