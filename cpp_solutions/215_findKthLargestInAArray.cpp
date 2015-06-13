bool compare(int i, int j){
    return i > j;
}

class Solution {
public:
    // TODO: adopt quick sort or max-heap
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), compare);
        return nums[k - 1];
    }
};