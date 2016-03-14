class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int partition_index = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                partition_index = i;
                break;
            }
        }
        if (partition_index >= 0 ) {
            int change_index = -1;
            for (int i = nums.size()-1; i >= 0; i--) {
                if (nums[i] > nums[partition_index]) {
                    change_index = i;
                    break;
                }
            }
            if (change_index > 0) {
                int tmp = nums[partition_index];
                nums[partition_index] = nums[change_index];
                nums[change_index] = tmp;
            }
        }

        for (int i = partition_index+1, j = nums.size()-1; i < j; i++, j--) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};
