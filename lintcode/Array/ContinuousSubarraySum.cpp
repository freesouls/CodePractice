class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int s = 0;
        // int e = 0;
        int max_sum = INT_MIN;
        int sum = A[0];
        vector<int> res(2, 0);

        for (int i = 1; i < A.size(); i++) {

            if (sum > max_sum) {
                max_sum = sum;
                res[0] = s;
                res[1] = i-1;
            }

            if (sum < 0) {
                sum = 0;
                s = i;
                // e = i;
            }

            sum += A[i];

        }

        if (sum > max_sum) {
            res[0] = s;
            res[1] = A.size()-1;
        }

        return res;
    }
};
