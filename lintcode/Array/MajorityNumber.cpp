class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int can1 = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                can1 = nums[i];
                count++;
            }
            else {
                if (nums[i] == can1) {
                    count++;
                }
                else {
                    count--;
                }
            }
        }

        return can1;
    }
};
