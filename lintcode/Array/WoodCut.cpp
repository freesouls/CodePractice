class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here

        int right = 0;
        for (int i = 0; i < L.size(); i++) {
            right = std::max(right, L[i]);
        }
        int left = 1;

        while(left + 1 < right) {
            int mid = left + (right - left)/2;

            if (check(L, k, mid)) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        if(check(L, k, right)) {
            return right;
        }

        if(left != right && check(L, k, left)) {
            return left;
        }

        return 0;
    }


    bool check(vector<int> &L, int k, int len) {

        for (int i = 0; i < L.size(); i++) {
            k -= L[i]/len;
            if (k <= 0) {
                return true;
            }
        }
        return false;
    }
};
