class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    // 1 -> 1, 2 -> 2, 3 -> 5
    int numTrees(int n) {
        // write your code here
        if (n <= 0) {
            return 1;
        }

        vector<int> nums(n+1, 0);
        nums[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                nums[i] += nums[j-1]*nums[i-j];
            }
        }

        return nums[n];
    }
};

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    // 1 -> 1, 2 -> 2, 3 -> 5
    int numTrees(int n) {
        // write your code here
        if (n <= 0) {
            return 1;
        }

        vector<int> nums(n+1, 0);
        nums[0] = 1;
        nums[1] = 1;

        for (int i = 2; i <= n; i++) {

            for (int j = 1; j <= i; j++) {
                nums[i] += nums[j-1]*nums[i-j];
            }
        }

        return nums[n];
    }
};
