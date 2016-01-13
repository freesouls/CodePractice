// this question is very wired?, in the page, asks to use binary search,
// and is marked as hard, while I only scan through the array, the solution
// is the same as problem 153
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i+1]<nums[i]){
                return nums[i+1];
            }
        }
        return nums[0];
    }
};