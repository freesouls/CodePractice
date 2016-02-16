class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT32_MAX, b = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= a) {
                a = nums[i];
            }
            else if (nums[i] <= b) {
                b = nums[i];
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
