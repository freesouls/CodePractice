class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1 || k%n == 0){
            return;
        }
        
        k = k%n;
        
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n-1);
        
    }
    
    void inline reverse(vector<int>& nums, int start, int end){
        while(start < end){
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
    
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1 || k%n == 0){
            return;
        }
        
        k = k%n;
        
        nums.insert(nums.begin(), nums.begin()+(n-k), nums.end());
        nums.erase(nums.begin()+n, nums.end());
    }
};