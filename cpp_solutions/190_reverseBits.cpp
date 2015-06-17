class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++){
            res = (res << 1) + n%2; // n%2 is slower use something like n&1 will faster
            n = n >> 1;
        }
        return res;
    }
};