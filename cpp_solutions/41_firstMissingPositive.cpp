class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums);
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size() + 1;
    }

    void sort(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i + 1){
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]){
                    break;
                }
                int tmp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[tmp - 1] = tmp;
            }
        }
    }
};
