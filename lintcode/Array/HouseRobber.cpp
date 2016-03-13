class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<long long> res(nums.size() + 1, 0);
        vector<bool> used(nums.size() + 1, false);
        res[1] = nums[0];
        used[1] = true;

        for (int i = 1; i < nums.size(); i++) {
            res[i+1] = (used[i] ? res[i-1] : res[i]) + nums[i];

            if (res[i+1] > res[i]) {
                used[i+1] = true;
            }
            else{
                res[i+1] = res[i];
            }
        }
        return res[nums.size()];
    }
};
