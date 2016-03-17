class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end());
        for (int i = 1; i + 1 < nums.size(); i += 2) {
            nums[i] = nums[i] - nums[i+1];
            nums[i+1] = nums[i] + nums[i+1];
            nums[i] = nums[i+1] - nums[i];
        }
    }
};
