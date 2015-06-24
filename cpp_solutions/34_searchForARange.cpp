class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2, -1);
        if (nums.size()==0 || nums[0]>target || nums[nums.size() - 1] < target){
            return res;
        }
        
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int middle = (left + right)/2;
            if (nums[middle] > target){
                right = middle - 1; // the key for stop while, 
                // if use right = middle the while may enter infinity loop
            }
            else if(nums[middle] < target) {
                left = middle + 1;
            }
            else{ // nums[middle] == target
                left = middle;
                while(left>=0 && nums[left]==target){
                    left--;
                }
                left++;
                right = middle;
                while(right<nums.size() && nums[right]==target){
                    right++;
                }
                right--;
                res[0] = left;
                res[1] = right;
                return res;
            }
        }
        return res;
    }
};