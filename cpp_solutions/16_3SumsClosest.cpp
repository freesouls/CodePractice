class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        if (n <= 2){
            return 0;
        }
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]){ //skip duplicates
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int gap = abs(sum - target);
                if (gap < min_gap){
                    res = sum;
                    min_gap = gap;
                }

                if (sum < target){
                    j++;
                    while (nums[j] == nums[j-1]){ //skip duplicates
                        j++;
                    }
                }
                else{
                    k--;
                    while(nums[k] == nums[k+1]){ //skip duplicates
                        k--;
                    }
                }
            }
        }
        return res;
    }
};
