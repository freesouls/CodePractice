class Solution {
public:
    int getSum(int a, int b) {
        
        int a_bit = a&1;
        int b_bit = b&1;
        int carry = 0;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (a_bit && b_bit){
                res ^= carry << i;
                carry = 1;
            }
            else if (!a_bit && !b_bit) {
                res ^= carry << i;
                carry = 0;
            }
            else {
                if (carry == 1) {
                    carry = 1;
                }
                else {
                    res ^= 1 << i;
                    carry = 0;
                }
            }
            a >>= 1;
            b >>= 1;
            a_bit = a&1;
            b_bit = b&1;
        }
        return res;
    }
};
