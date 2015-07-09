class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1 = 0, can2 = 1;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == can1){
                count1++;
            }
            else if(nums[i] == can2){
                count2++;
            }
            else if(count1 == 0){
                can1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                can2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == can1){
                count1++;
            }
            else if (nums[i] == can2){
                count2++;
            }
        }
        
        vector<int> res;
        if (count1 > n/3){
            res.push_back(can1);
        }
        if (count2 > n/3){
            res.push_back(can2);
        }
        return res;
    }
};
