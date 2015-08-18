// http://www.cnblogs.com/jcliBlogger/p/4736809.html

/*
Problem Description:
Given an array of n integers nums and a target, find the number of index triplets i, j, k
with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n^2) runtime?
*/

class Solution {
public:
    // comman Solution: O(N^3)
    // but it can be O(N^2) in this code
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        int i, j, k;
        for (i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] >= target) k--;
                else {
                    ans += (k - j);
                    j++;
                }
            }
        }
        return ans;
    }
};
