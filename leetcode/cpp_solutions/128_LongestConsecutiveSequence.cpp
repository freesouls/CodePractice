// 24ms
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

// 24ms
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++ ) {
            s.insert(nums[i]);
        }
        
        int max_cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                int cnt = 1;
                s.erase(nums[i]);
                int val = nums[i]-1;
                while(s.find(val) != s.end()) {
                    cnt++;
                    s.erase(val);
                    val--;
                }
                
                val = nums[i]+1;
                while(s.find(val) != s.end()) {
                    cnt++;
                    s.erase(val);
                    val++;
                }
                
                if (cnt > max_cnt) {
                    max_cnt = cnt;
                }
            }
            
        }
        return max_cnt;
    }
};
