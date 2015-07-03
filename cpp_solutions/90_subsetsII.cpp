class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<int> vec;
        get(nums, vec, 0);
        return res;
    }

    void get(vector<int>& nums, vector<int>& vec, int index){
        res.push_back(vec);
        for(int i = index; i < n; i++){
            if (i > index && nums[i] == nums[i-1]){
                continue;
            }
            vec.push_back(nums[i]);
            get(nums, vec, i + 1);
            vec.pop_back();
        }
    }

};
