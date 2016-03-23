class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int num = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            num ^= nums[i];
            num ^= i;
        }
        return num;
    }
};
