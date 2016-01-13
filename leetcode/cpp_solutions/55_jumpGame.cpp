class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size();
        for(int i = 0; i <= reach && reach < n - 1; i++){
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};
