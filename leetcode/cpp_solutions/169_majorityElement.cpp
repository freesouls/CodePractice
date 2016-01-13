class Solution {
public:
    // https://www.wikiwand.com/en/Boyer-Moore_Majority_Vote_Algorithm
    int majorityElement(vector<int>& nums) {
        int can;
        int nTimes = 0;
        int n = nums.size();
        int half = n/2;
        for (int i = 0; i < n; i++){
            if(nTimes == 0){
                can = nums[i];
                nTimes++;
            }
            else{
                if(can == nums[i]){
                    nTimes++;
                    if (nTimes > half){
                    // since the problem says nTimes will always more than ⌊n/2⌋ times
                    // otherwise nTime >= half should be considered
                        return can;
                    }
                }
                else{
                    nTimes--;
                }
            }
        }
        return can;
    }
};

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can;
        int nTimes = 0;
        int n = nums.size();
        int half;

        for (int i = 0; i < n; i++){
            if(nTimes == 0){
                can = nums[i];
                nTimes++;
            }
            else{
                if(can == nums[i]){
                    nTimes++;
                }
                else{
                    nTimes--;
                }
            }
        }
        return can;
    }
};
*/
