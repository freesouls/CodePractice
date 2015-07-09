class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size() - 1;
        for(int i = 0; i < blue + 1; ){
            if (nums[i] == 0){
                int tmp = nums[red];
                nums[red] = nums[i];
                nums[i] = tmp;
                i++;
                red++;
            }
            else if(nums[i] == 2){
                int tmp = nums[blue];
                nums[blue] = nums[i];
                nums[i] = tmp;
                blue--;
            }
            else{
                i++;
            }
        }
    }
};
