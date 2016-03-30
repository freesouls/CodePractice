class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        vector<int> left_max(nums.size(), INT_MIN);
        vector<int> left_min(nums.size(), INT_MAX);
        vector<int> right_max(nums.size(), INT_MIN);
        vector<int> right_min(nums.size(), INT_MAX);

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
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            left_min[i] = sum;
            if (i > 0) {
                left_min[i] = std::min(left_min[i-1], left_min[i]);
            }

            if (sum > 0) {
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

        sum = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            sum += nums[i];
            right_min[i] = sum;
            if (i != nums.size()-1) {
                right_min[i] = std::min(right_min[i], right_min[i+1]);
            }

            if (sum > 0) {
                sum = 0;
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (i+1 < nums.size()) {
                res = std::max(res, abs(left_max[i] - right_min[i+1]));
                res = std::max(res, abs(left_min[i] - right_max[i+1]));
            }
            if (i-1 >= 0) {
                res = std::max(res, abs(left_max[i-1] - right_min[i]));
                res = std::max(res, abs(left_min[i-1] - right_max[i]));
            }
        }
        return res;
    }
};
