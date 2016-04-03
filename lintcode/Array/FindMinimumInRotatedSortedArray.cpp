class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        return search(nums, 0, nums.size()-1);
    }

    int search(vector<int> & nums, int left, int right) {
        if (left <= right) {
            if (nums[left] <= nums[right]) {
                return nums[left];
            }
            else {
                int mid = left + (right - left)/2;
                return min(search(nums, left, mid), search(nums, mid+1, right));
            }
        }
        return INT_MAX;
    }
};
