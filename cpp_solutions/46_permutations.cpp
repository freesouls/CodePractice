class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() == 0) return res;
        vector<int> current;
        permute(res, current, nums);
        return res;
        
        // version two, can be adapt the next permutation function in question 31
    }
    
    void permute(vector<vector<int> >& res, vector<int>& current, vector<int>& nums){
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if (std::find(current.begin(), current.end(), nums[i]) == current.end()){
                current.push_back(nums[i]);
                permute(res, current, nums);
                current.pop_back();
            }
        }
    }
};