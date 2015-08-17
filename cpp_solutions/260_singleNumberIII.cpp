class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;

        if (nums.size() == 0) {
            return res;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum ^= nums[i]; //bitwise xor
        }
        int k = -1;
        for (int i = 0; i < 32; i++){
            if( ((sum >> i) & 1) == 1 ) { // bitwise and
                k = i;
                break;
            }
        }

        int a = 0, b = 0;

        for (int i = 0; i < nums.size(); i++){
            if ( ((nums[i] >> k) & 1) == 1 ){
                a ^= nums[i];
            }
            else {
                b ^= nums[i];
            }
        }

        res.push_back(a);
        res.push_back(b);
        return res;
    }
};
