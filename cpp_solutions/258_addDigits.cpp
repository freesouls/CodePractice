class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }

        num %= 9;

        if (num) {
            return num;
        }
        else {
            return 9;
        }

    }
};
