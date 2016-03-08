/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */

    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> sums(A.size()+1, 0);
        for (int i = 0; i < A.size(); i++) {
            sums[i+1] = A[i] + sums[i];
        }

        vector<long long> res(queries.size(), 0LL);
        for (int i = 0; i < queries.size(); i++) {
            Interval range = queries[i];
            res[i] = sums[range.end+1]-sums[range.start];
        }
        return res;
    }
};
