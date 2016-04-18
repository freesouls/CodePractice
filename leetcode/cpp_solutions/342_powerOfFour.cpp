class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num&(num-1)) == 0 && (num & 0x55555555) != 0;
        //0x55555555 is to get rid of those power of 2 but not power of 4
        //so that the single 1 bit always appears at the odd position
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num && (num % 4 == 0)) {
            num /= 4;
        }
        return num == 1;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;
    }
};
