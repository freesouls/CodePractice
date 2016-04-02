class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cnt1 = 0, cnt2 = 0;
        int can1 = 0, can2 = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == can1) {
                cnt1++;
            }
            else if(nums[i] == can2) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                can1 = nums[i];
                cnt1++;
            }
            else if (cnt2 == 0) {
                can2 = nums[i];
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == can1) {
                cnt1++;
            }
            else if (nums[i] == can2) {
                cnt2++;
            }
        }

        if (cnt1 > nums.size()/3) {
            return can1;
        }
        return can2;
    }
};
