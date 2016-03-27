class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }

        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            while(i < nums.size() && nums[i] < k) {
                i++;
            }

            while(j >= 0 && nums[j] >= k) {
                j--;
            }

            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }
        return i;
    }
};
