class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == A[mid]) {
                return mid;
            }

            // it must be ">=", for mid == left in some cases.
            if (A[mid] >= A[left]) { // the left part is in sorted order
                if (A[left] <= target && target <= A[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else { // A[left] > A[mid] ==> A[mid]-A[right] is increasing
                /*
                if (A[mid] <= target && target <= A[right]) {
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                } // it is the same as the below codes
                */
                if (A[mid] >= target || target >= A[left]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};


class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == A[mid]) {
                return mid;
            }

            // it must be ">=", for mid == left in some cases.
            if (A[mid] >= A[left]) { // the left part is in sorted order
                if (A[left] <= target && target <= A[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else { // A[mid] < A[left]
                if (A[mid] <= target && target <= A[right]) {
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }

                // if (A[mid] >= target || target >= A[left]) {
                //     right = mid - 1;
                // }
                // else {
                //     left = mid + 1;
                // }
            }
        }
        return -1;
    }
};
