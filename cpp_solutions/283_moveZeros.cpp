class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[start++] = nums[i];
            }
        }
        
        for (int i = start; i < nums.size(); i++) {
            nums[i] = 0;
        }
        
    }
};
