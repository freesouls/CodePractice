class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for (int i = 0; i < nums.size(); i++){
            used[nums[i]] = false;
        }
        int len = 0;
        for (int i = 0; i < nums.size(); i++){
            if (used[nums[i]]){
                continue;
            }
            used[nums[i]] = true;
            int cur = 1;
            for (int j = nums[i] + 1; used.find(j) != used.end(); j++){
                cur++;
                used[j] = true;
            }
            for (int j = nums[i] - 1; used.find(j) != used.end(); j--){
                cur++;
                used[j] = true;
            }
            len = max(len, cur);
        }
        return len;
    }
};
