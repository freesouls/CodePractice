class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0){
            return 0;
        }
        int cur = nums[0];
        int ptr = 0;
        bool flag = false;
        for (int i=0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[ptr] = nums[i];
                ptr++;
                flag = true;
            }
        }
        if (flag){
            return ptr++;
        }
        else{
            return 0;   
        }
    }
};