class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        if (k <= 0 || nums.size() < k) {
            return 0;
        }
        return kth(nums, 0, nums.size()-1, k);
    }

    int kth(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];
        int i = left, j  = left;
        for (int i = left; i < right; i++) {
            if (nums[i] > pivot) { // >= is also OK
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++;
            }
        }

        int tmp = nums[right];
        nums[right] = nums[j];
        nums[j] = tmp;

        if (j + 1 == k) {
            return pivot;
        }
        else if (j + 1 > k) {
            return kth(nums, left, j - 1, k);
        }
        else {
            return kth(nums, j + 1, right, k);
        }

    }

};
