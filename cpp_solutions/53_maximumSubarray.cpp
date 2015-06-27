class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        int res = INT_MIN;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++){
            tmp += nums[i];
            if (tmp > res){
                res = tmp;
            }
            if(tmp < 0){
                tmp = 0;
            }
        }
        return res;
    }
};
