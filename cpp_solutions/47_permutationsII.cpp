class Solution {
public:
    // to do iterative VERSION !!!
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() == 0) return res;
        std::sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(nextPermutation(nums)){
            res.push_back(nums);
        }
        //res.push_back(nums);
        return res;
    }
    
    bool nextPermutation(vector<int>& nums) {
        int change_pos = -1;
        for(int i = nums.size() - 1; i > 0; i--){
            if (nums[i - 1] < nums[i]){
                change_pos = i - 1;
                break;
            }
        }
        
        if (change_pos == -1){
            reverse(nums, 0, nums.size()-1);
            return false;
        }
        
        int next_pos = -1;
        int delta = INT_MAX;
        for(int i = nums.size() - 1; i > change_pos; i--){
            int tmp = nums[i] - nums[change_pos];
            if (tmp > 0 && tmp < delta){
                next_pos = i;
                delta = tmp;
            }
        }
        
        int tmp = nums[change_pos];
        nums[change_pos] = nums[next_pos];
        nums[next_pos] = tmp;
        
        reverse(nums, change_pos + 1, nums.size() - 1);
        return true;
    }
    
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    
};