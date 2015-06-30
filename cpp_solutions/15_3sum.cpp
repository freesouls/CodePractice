class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int n =  nums.size();
        if (n <= 2){
            return res;
        }
        std::sort(nums.begin(), nums.end());
        bool flag = false;
         for(int i = 0; i < n - 2; i++){
            if (nums[i] + nums[i+1] > 0){
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i + 1; j < n - 1; j++){
                int tmp = nums[i] + nums[j];
                if (tmp > 0){
                    break;
                }
                if (tmp + nums[n-1] < 0 || (j > i+1 && nums[j] == nums[j-1])){
                    continue;
                }
                for (int k = j + 1; k < n; k++){
                    if (tmp + nums[k] > 0){
                        break;
                    }
                    else if (tmp + nums[k] < 0){// || (k > j + 1 && nums[k] == nums[k-1])){
                        continue;               // use break in else can avoid this check
                    }
                    else{
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        res.push_back(t);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
