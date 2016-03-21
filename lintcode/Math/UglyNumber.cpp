class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        if (num <= 0) {
            return false;
        }
        while (num > 1) {
            if (num % 2 == 1) {
                break;
            }
            num /= 2;
        }

        while (num > 1) {
            if (num % 3 > 0) {
                break;
            }
            num /= 3;
        }

        while (num > 1) {
            if (num % 5 > 0) {
                break;
            }
            num /= 5;
        }

        return num == 1;
    }
};
