class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        int cur = nums[0];
        int ptr = 1;
        int count = 1;
        for ( int i=1; i < nums.size(); i++){
            if (nums[i] == cur){
                if(count < 2){
                    count++;
                    nums[ptr] = nums[i];
                    ptr++;
                }
            }
            else{
                nums[ptr] = nums[i];
                cur = nums[ptr];
                ptr++;
                count = 1;
            }
        }
        return ptr;
    }
};