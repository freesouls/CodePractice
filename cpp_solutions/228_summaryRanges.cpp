class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int start = 0;
        int stop = 0;
        for (int i = 0; i < nums.size(); i++) {
            start = i;
            stop = i;
            int j = i + 1;
            for (; j < nums.size(); j++){
                if (nums[j]-nums[j-1] != 1) {
                    break;
                }
                stop++;
            }
            if(start == stop){
                res.push_back(std::to_string(nums[start]));
            }
            else{
                res.push_back(std::to_string(nums[start])+"->"+std::to_string(nums[stop]));
            }
            i = j - 1;
        }
        return res;
    }
};
