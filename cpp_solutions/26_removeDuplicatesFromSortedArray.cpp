class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        /*  // version 1
        int cur = nums[0];
        int ptr = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != cur){
                nums[ptr - 1] = cur;
                ptr++;
                cur = nums[i];
            }
        }
        nums[ptr - 1] = cur;
        return ptr;
        */
        int cur = nums[0];
        int ptr = 1;
        for ( int i=1; i < nums.size(); i++){
            if(nums[i] != cur){
                nums[ptr] = nums[i];
                cur = nums[ptr];
                ptr++;
            }
        }
        return ptr;
    }
};