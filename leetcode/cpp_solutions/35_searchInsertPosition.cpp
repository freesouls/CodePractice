class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0 || target <= nums[0]){
            return 0;
        }
        if (target > nums[nums.size()-1]){
            return nums.size();
        }
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] >= target){
                return i;
            }
        }
        return 0;
    }
};