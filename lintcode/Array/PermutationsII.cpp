class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here

        sort(nums.begin(), nums.end());
        vector<int> dup_cnts;
        for (int i = 1; i < nums.size(); i++) {
            int cnt = 1;
            while(nums[i] == nums[i-1]) {
                cnt++;
                i++;
            }
            if (cnt > 1) {
                dup_cnts.push_back(cnt);
            }
        }

        long long cnt = factor(nums.size());

        for (int i = 0; i < dup_cnts.size(); i++) {
            cnt /= factor(dup_cnts[i]);
        }

        vector<vector<int> > res;
        res.push_back(nums);
        while(cnt > 1) {
            nextPermutation(nums);
            res.push_back(nums);
            cnt--;
        }
        return res;
    }

    long long factor(int n){
        long long i = 1;
        while(n > 1) {
            i *= n;
            n--;
        }
        return i;
    }

    void nextPermutation(vector<int>& nums) {
        int partition_index = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                partition_index = i;
                break;
            }
        }
        if (partition_index >= 0 ) {
            int change_index = -1;
            for (int i = nums.size()-1; i >= 0; i--) {
                if (nums[i] > nums[partition_index]) {
                    change_index = i;
                    break;
                }
            }
            if (change_index > 0) {
                int tmp = nums[partition_index];
                nums[partition_index] = nums[change_index];
                nums[change_index] = tmp;
            }
        }

        for (int i = partition_index+1, j = nums.size()-1; i < j; i++, j--) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};
