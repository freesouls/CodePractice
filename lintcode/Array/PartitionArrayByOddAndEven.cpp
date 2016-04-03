class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int i = 0;
        int j = nums.size()-1;

        while(i < j) {
            while(nums[i]%2 == 1) {
                i++;
            }
            while(nums[j]%2 == 0) {
                j--;
            }

            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
};
