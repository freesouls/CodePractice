class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++){
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};

class Solution {
public:
    //may be overflow
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        for (int i = 0; i < n; i++){
            sum -= nums[i];
        }
        return sum;
    }
};
