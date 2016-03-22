class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        sort(A);
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != i + 1) {
                return i+1;
            }
        }
        return A.size() + 1;
    }

    // O(N)
    void sort(vector<int>& nums){
        for (int i = 0; i < nums.size(); i++) {
            while(nums[i] != i+1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i]-1]) {
                    break;
                }
                int tmp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[tmp-1] = tmp;
            }
        }
    }
};
