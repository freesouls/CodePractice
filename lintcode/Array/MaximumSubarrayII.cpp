class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        vector<int> left_max(nums.size(), INT_MIN);
        vector<int> right_max(nums.size(), INT_MIN);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            left_max[i] = sum;
            if (i > 0) {
                left_max[i] = std::max(left_max[i-1], left_max[i]);
            }

            if (sum < 0) {
                sum = 0;
            }

        }

        sum = 0;

        for (int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            right_max[i] = sum;
            if (i != nums.size()-1) {
                right_max[i] = std::max(right_max[i], right_max[i+1]);
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (i+1 < nums.size()) {
                res = std::max(res, left_max[i] + right_max[i+1]);
            }
            if (i-1 >= 0) {
                res = std::max(res, left_max[i-1] + right_max[i]);
            }
        }
        return res;
    }
};
