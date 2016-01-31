class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        if (n > 0) {
            sums.resize(n, 0);
            sums[0] = nums[0];
            for (int i = 1; i < n; i++) {
                sums[i] = sums[i-1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sums[j];
        }
        else {
            return sums[j] - sums[i-1];
        }
    }
};

class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        sums.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i+1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};
