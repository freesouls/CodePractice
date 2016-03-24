class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }

        int res_max = nums[0];
        int res_min = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tmp = res_max;
            res_max = std::max(nums[i], std::max(res_max*nums[i], res_min*nums[i]));
            res_min = std::min(nums[i], std::min(tmp*nums[i], res_min*nums[i]));
            res = std::max(res, res_max);
        }

        return res;
    }
};
