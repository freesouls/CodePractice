class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        vector<int> index(primes.size(), 1);
        sort(primes.begin(), primes.end());
        vector<int> nums = primes;

        vector<int> res(n, 0);
        res[0] = 1;
        int min = primes[0];
        int i = 1;
        while( i < n) {
            res[i] = min;
            int tmp_min = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                if (min == nums[j]) {
                    nums[j] = res[index[j]]*primes[j];
                    index[j]++;
                }
                tmp_min = std::min(tmp_min, nums[j]);
            }
            min = tmp_min;
            i++;
        }

        return res[n-1];
    }
};
