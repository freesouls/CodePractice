class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == A[mid]) {
                return true;
            }

            if (A[mid] > A[left]) { // the left part is in sorted order
                if (A[left] <= target && target <= A[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (A[left] > A[mid]){ // A[left] > A[mid] ==> A[mid]-A[right] is increasing

                if (A[mid] <= target && target <= A[right]) {
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                } // it is the same as the below codes
                /*
                if (A[mid] >= target || target >= A[left]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
                */
            }
            else { // A[mid] == A[left] means A[mid] != target
                left++;
            }

        }
        return false;
    }
};
