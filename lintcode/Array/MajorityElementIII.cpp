class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    // time O(N*K)
    // use hashmap will be O(N)
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        vector<int> cans(k-1, 0);
        for (int i = 0; i < k-1; i++) {
            cans[i] = i;
        }
        vector<int> cnts(k-1, 0);

        for (int i = 0; i < nums.size(); i++) {
            bool flag = false;
            for (int j = 0; j < k-1; j++) {
                if (nums[i] == cans[j]) {
                    cnts[j]++;
                    flag = true;
                    break;
                }
            }

            if (flag) {
                continue;
            }
            flag = false;
            for (int j = 0; j < k-1; j++) {
                if (cnts[j] == 0) {
                    cans[j] = nums[i];
                    cnts[j]++;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }

            for (int j = 0; j < k-1; j++) {
                cnts[j]--;
            }
        }

        for (int j = 0; j < k-1; j++) {
            cnts[j] = 0;
        }

        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < k-1; j++) {
                if (nums[i] == cans[j]) {
                    cnts[j]++;
                }
            }
        }

        for (int j = 0; j < k-1; j++) {
            if (cnts[j] > nums.size()/k) {
                return cans[j];
            }
        }

        return 0;
    }
};
