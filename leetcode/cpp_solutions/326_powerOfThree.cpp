class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            int r = n%3;
            if (r != 0) {
                return false;
            }
            n /= 3;
        }

        return true;
    }
};
