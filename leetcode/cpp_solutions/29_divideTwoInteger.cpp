class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        long long res = 0;
        while (a >= b){
            long long c = b;
            for(int i = 1; a >= c; i <<= 1, c <<= 1){
                a -= c;
                res += i;
            }
        }
        
        return (dividend^divisor)>>31 ? -res:(res >= INT_MAX ? INT_MAX : res);
    }
    
/*
C中int类型32位,范围是-2147483648到2147483647.
（1）最轻微的上溢是 INT_MAX + 1 ：结果是 INT_MIN。 
（2）最严重的上溢是 INT_MAX + INT_MAX ：结果是 -2。 
（3）最轻微的下溢是 INT_MIN - 1 ：结果是 INT_MAX。 
（4）最严重的下溢是 INT_MIN +INT_MIN ：结果是 0。
*/
};