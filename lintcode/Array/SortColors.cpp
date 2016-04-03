class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size()-1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0){
                int tmp = nums[left];
                nums[left] = nums[i];
                nums[i] = tmp;
                left++;
            }
            else if (nums[i] == 2) {
                int tmp = nums[right];
                nums[right] = nums[i];
                nums[i] = tmp;
                right--;
                i--;
            }
        }
    }
};
