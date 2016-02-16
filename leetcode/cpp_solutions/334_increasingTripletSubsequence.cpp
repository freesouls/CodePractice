class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // if (nums.size() < 3) {
        //     return false;
        // }

        // int a = std::min(nums[0], nums[1]);
        // // int a = nums[0];
        // int b = nums[1];
        // bool flag = a < b;
        int a = INT32_MAX, b = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= a) {
                a = nums[i];
                // continue;
            }
            else if (nums[i] <= b) {
                b = nums[i];
                // continue;
            }
            else {
                return true;
            }
        }
        return false;
    }

};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT32_MAX, b = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= a) {
                a = nums[i];
            }
            else{
                if ( a < b ) {
                    if ( nums[i] > b) {
                        return true;
                    }
                    else {
                        b = nums[i];
                    }
                }
                else {
                    b = nums[i];
                }
            }
        }
        return false;
    }

};
