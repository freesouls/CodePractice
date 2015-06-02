class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /* // version 1, O(N), but need more time when construct hashmap
        map<int, int> dic;
        for(int i = 0; i < nums.size(); i++){
            if(dic.find(nums[i]) == dic.end()){
                dic[nums[i]] = 1;
            }
            else{
                return true;
            }
        }
        return false;
        */
        // actually faster than version 1, O(NlogN)
        if (nums.size() <2){
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};