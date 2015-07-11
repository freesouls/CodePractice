class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int min = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum >= s){
                while(sum >= s){
                    int len = i - start + 1;
                    if (len < min){
                        min = len;
                        if (min == 1){ // this can be used for prunning
                            return 1;
                        }
                    }
                    sum -= nums[start++];
                }
            }
        }

        if (min == INT_MAX){
            return 0;
        }
        else{
            return min;
        }
    }
};
