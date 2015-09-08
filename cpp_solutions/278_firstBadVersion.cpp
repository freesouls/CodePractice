// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right) {
            int middle =  (right - left)/2 + left;
            if (isBadVersion(middle)) {
                right = middle;
            }
            else{
                left = middle;
            }
            if (left+1 == right) {
                if (isBadVersion(left)){
                    return left;
                }
                else {
                    return right;
                }
            }
        }
        return left;
    }
};
