class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2){
            return 0;
        }

        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] < min){
                min = nums[i];
            }
            if (nums[i] > max){
                max =  nums[i];
            }
        }

        if (max - min <= 1){ // prunning
            return max - min;
        }

        int bucketLen = (max - min)/nums.size() + 1;
        int bucketNum = (max - min)/bucketLen + 1;

        vector<int> tmp(2, INT_MAX); // (min, max) for a bucket
        tmp[1] = INT_MIN;
        vector<vector<int>> records(bucketNum, tmp);
        for (int i = 0; i < nums.size(); i++){
            int ind = (nums[i] - min)/bucketLen;
            if (nums[i] < records[ind][0]){
                records[ind][0] = nums[i];
            }
            if (nums[i] > records[ind][1]){
                records[ind][1] = nums[i];
            }
        }

        int res = 0;
        int pre_max = records[0][1]; // we can gurantee records[0][1] != INT_MIN
        for (int i = 1; i < bucketNum; i++){
            if (records[i][0] != INT_MAX){
                res = std::max(res, records[i][0] - pre_max);
                pre_max = records[i][1];
            }
        }
        // int flag = true;
        // int pre_max = 0;
        // for (int i = 0; i < bucketNum; i++){
        //     if (records[i][0] != INT_MAX){
        //         if (flag){
        //             pre_max = records[i][1];
        //             flag = false;
        //         }
        //         else{
        //             res = std::max(res, records[i][0] - pre_max);
        //             pre_max = records[i][1];
        //         }
        //     }
        // }

        return res;
    }

    int maximumGap2(vector<int>& nums) {
        if (nums.size() < 2){
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int max = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            max = std::max(nums[i+1]-nums[i], max);
        }
        return max;
    }
};
