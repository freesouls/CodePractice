class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int sum = 0;
        int start = 0;
        int min_len = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s && start <= i) {
                min_len = std::min(min_len, i - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return min_len == INT_MAX ? -1 : min_len;
    }
};
