class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty()) return result;

        int lb = -1, ub = nums.size();
        while (lb + 1 < ub) {
            int mid = lb + (ub - lb) / 2;
            if (nums[mid] < target) lb = mid;
            else ub = mid;
        }

        if ((ub < nums.size()) && (nums[ub] == target)) result[0] = ub;
        else return result;

        ub = nums.size();
        while (lb + 1 < ub) {
            int mid = lb + (ub - lb) / 2;
            if (nums[mid] > target) ub = mid;
            else lb = mid;
        }
        result[1] = ub - 1;
        return result;
    }
};


class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    // directly search for lower and upper bound
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;

        vector<int> res(2, -1);
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == A[mid]) {
                res[0] = getBound(A, left, mid, 1);
                res[1] = getBound(A, mid, right, 0);
                return res;
            }
            else if(target > A[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return res;
    }

    int getBound(vector<int>& A, int left, int right, int flag) {

        if (flag) {
            if (A[left] == A[right]) {
                return left;
            }
            int mid = left + (right - left)/2;
            if (A[mid] < A[right]) {
                return getBound(A, mid+1, right, 1);
            }
            else {
                return getBound(A, left, mid, 1);
            }
        }
        else {

            if (left + 1 >= right) {
                if (A[right] == A[left]) {
                    return right;
                }
                return left;
            }
            int mid = left + (right - left)/2;

            if (A[left] < A[mid]) {
                return getBound(A, left, mid-1, 0);
            }
            else {
                return getBound(A, mid, right, 0);
            }
        }
    }
};
