//http://blog.csdn.net/linhuanmars/article/details/39537283
// TODO: another solution with judging whether nums[i] < = > 0
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        if (nums.size() == 1){
            return nums[0];
        }
        int max_local = nums[0];
        int min_local = nums[0];
        int global = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int max_copy = max_local;
            max_local = max(max(nums[i], nums[i]*max_local), min_local*nums[i]);
            min_local = min(min(nums[i], nums[i]*max_copy), min_local*nums[i]);
            global = max(max_local, global);
        }
        return global;
    }
};

/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        if (nums.size() == 1){
            return nums[0];
        }

        int res = nums[0];
        int pos = max(0, nums[0]);
        int neg = min(0, nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                pos = 0;
                neg = 0;
            } else if (nums[i] > 0) {
                pos = max(1, pos)*nums[i];
                neg = neg*nums[i];
            } else {
                int pos_old = pos;
                pos = neg*nums[i];
                neg = min(nums[i], nums[i]*pos_old);
            }
            res = max(res, pos);
        }
        return res;
    }
};
*/
