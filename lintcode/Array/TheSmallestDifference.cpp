class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int res = INT_MAX;
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()) {
            res = std::min(res, abs(A[i]-B[j]));
            if (A[i] < B[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        int tmp = B[B.size()-1];
        while(i < A.size()) {
            res = std::min(res, abs(A[i]-tmp));
            i++;
        }

        tmp = A[A.size()-1];
        while(j < B.size()) {
            res = std::min(res, abs(tmp-B[j]));
            j++;
        }

        return res;
    }


};
