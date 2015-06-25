class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        // find the common left header (or, same prefix) of m and n
        while(m != n){
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
};