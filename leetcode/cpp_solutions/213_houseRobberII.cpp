class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }


    int rob(vector<int>& nums, int start, int end) {
        int pre_pre = 0;
        int pre = 0;
        bool pre_used = false;
        for (int i = start; i < end; i++) {
            int res = (pre_used ? pre_pre : pre) + nums[i];

            if (res > pre) {
                pre_used = true;
            }
            else {
                res = pre;
            }

            pre_pre = pre;
            pre = res;
        }

        return pre;
    }
};

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

        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }

    int rob(vector<int>& nums, int start, int end) {
        // if (end - start == 0) {
        //     return 0;
        // }
        //
        // if (end - start == 1){
        //     return nums[start];
        // }

        if (end - start == 2){
            return max(nums[start], nums[start + 1]);
        }
        int pre = 0;
        int one = nums[start];
        int two = max(nums[start], nums[start + 1]);
        one = max(one + nums[start + 2], two);
        pre = nums[start];
        for (int i = start + 3; i < end; i++){
            if ((i-start)%2){
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
