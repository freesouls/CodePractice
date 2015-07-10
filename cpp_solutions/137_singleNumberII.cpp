class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int W = sizeof(int)*8;
        int count[W];
        fill(count, count+W, 0);
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < W; j++){
                count[j] += (nums[i] >> j)&1;
            }
        }
        int res = 0;
        for(int i = 0; i < W; i++){
            res +=((count[i]%3) << i);
        }
        return res;
    }
};
