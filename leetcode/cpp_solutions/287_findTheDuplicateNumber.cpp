// https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) {
            int fast = nums[nums[0]];
            int slow = nums[0];

            while (fast != slow) {
                fast = nums[nums[fast]];
                slow = nums[slow];
            }

            fast = 0;
            while(fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        // this is impossible under the problem setting
        return 0;
    }
};
