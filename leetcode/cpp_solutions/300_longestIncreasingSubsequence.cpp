// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// N*log(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> tailTable(nums.size(), 0);

        int len = 1;
        tailTable[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < tailTable[0]) {
                tailTable[0] = nums[i];
            }
            // nums[i] >= tailTable[len-1] for no-decreasing 
            else if (nums[i] > tailTable[len - 1]) {
                tailTable[len++] = nums[i];
            }
            else {
                int index = findCeilingIndex(tailTable, nums[i], 0, len - 1);
                tailTable[index] = nums[i];
            }
        }

        return len;
    }

    int findCeilingIndex(vector<int> &nums, int key, int left, int right) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= key) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return right;
    }
};

// O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> cnts(nums.size(), 1);

        int max_cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            int j = i - 1;
            int tmp_max = 0;
            while (j >= 0) {
                if (nums[j] < nums[i]) {
                    if (cnts[j] > tmp_max){
                        tmp_max = cnts[j];
                    }
                }
                j--;
            }
            cnts[i] += tmp_max;
            if (cnts[i] > max_cnt) {
                max_cnt = cnts[i];
            }
        }

        return max_cnt;
    }
};
