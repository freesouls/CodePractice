class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        for (int i = 1; i < A.size() - 1; i++) {
            if (A[i] > A[i-1] && A[i] > A[i+1]) {
                return i;
            }
        }
        return -1;
    }
};
