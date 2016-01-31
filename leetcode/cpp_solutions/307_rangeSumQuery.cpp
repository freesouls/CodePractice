// http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
class NumArray {
    vector<int> numbers;
    vector<int> sums;
    int n;
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        numbers.resize(n, 0);
        sums.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i, nums[i]);
        }
    }


    void update(int i, int val) {
        int sub = val - numbers[i];
        int index = i + 1;
        while(index <= n) {
            sums[index] += sub;
            index += index & (-index);
        }

        numbers[i] = val;
    }

    int getSum(int index) {
        int sum = 0; // Iniialize result
        // index in BITree[] is 1 more than the index in arr[]
        index = index + 1;
        // Traverse ancestors of BITree[index]
        while (index > 0)
        {
            // Add current element of BITree to sum
            sum += sums[index];

            // Move index to parent node in getSum View
            index -= index & (-index);
        }
        return sum;
    }

    int sumRange(int i, int j) {

        return getSum(j) - getSum(i - 1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

// TLE
class NumArray {
    vector<int> numbers;
    vector<int> sums;
    vector<int> subs;
    vector<bool> updated;
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    // bool updated;
    // int sub = 0;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        numbers = nums;
        sums.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        subs.resize(n, 0);
        updated.resize(n, false);
        // min_heap.clear();
        // updated = false;
    }

    void update(int i, int val) {
        int sub = val - numbers[i];
        if (updated[i]) {
            subs[i] += sub;
        }
        else {
            subs[i] = sub;
            updated[i] = true;
            min_heap.push(i);
        }

        numbers[i] = val;
    }

    int sumRange(int i, int j) {
        int tmp_sub = 0;
        while (min_heap.size() > 0) {
            int cur_index = min_heap.top();
            min_heap.pop();
            updated[cur_index] = false;
            tmp_sub += subs[cur_index];
            int next_index = sums.size() - 1;
            if (min_heap.size() > 0) {
                next_index = min_heap.top();
            }

            for (int k = cur_index + 1; k <= next_index; k++) {
                sums[k] += tmp_sub;
            }
        }

        return sums[j + 1] - sums[i];
    }
};

// TLE
class NumArray {
    vector<int> numbers;
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        numbers = nums;
        sums.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    void update(int i, int val) {
        int origin = numbers[i];
        int sub = val - origin;
        for (int j = i + 1; j < sums.size(); j++) {
            sums[j] += sub;
        }
        numbers[i] = val;
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
