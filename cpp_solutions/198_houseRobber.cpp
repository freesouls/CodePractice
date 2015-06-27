// TODO: A general way
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1){
            return nums[0];
        }

        if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        int pre = 0;
        int one = nums[0];
        int two = max(nums[0], nums[1]);
        one = max(one + nums[2], two);
        pre = nums[0];
        for (int i = 3; i < nums.size(); i++){
            if (i%2){
                int tmp = two;
                two = max(pre + nums[i], two + nums[i]);
                pre = tmp;
            }
            else{
                int tmp = one;
                one = max(one + nums[i], pre + nums[i]);
                pre = tmp;
            }
        }
        return max(one, two);
    }
};
