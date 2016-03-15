class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if (nums.size() == 0){
            return 0;
        }

        vector<int> trace_list_table(nums.size(), 0);
        int len = 1;
        trace_list_table[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // nums[i] > trace_list_table[len-1] if the problem what strictly increasing
            if (nums[i] >= trace_list_table[len-1]) {
                trace_list_table[len] = nums[i];
                len++;
            }
            else {
                int index = findCeilingIndex(trace_list_table, nums[i], len);
                trace_list_table[index] = nums[i];
            }
        }
        return len;
    }

    int findCeilingIndex(vector<int> & table, int num, int end){
        int left = 0;
        int right = end - 1;

        while(left < right) {
            int mid = (left + right)/2;
            if (table[mid] < num) {
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return right;
    }

    int findCeilingIndex2(vector<int> & table, int num, int len) {
        int i = len-1;
        for (; i >= 0; i--) {
            if (table[i] < num) {
                break;
            }
        }

        return i + 1;
    }
};
