class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        int divisor = 5;
        while(n > 4){
            n /= 5;
            count += n;
        }
        return count;
    }
    
    // int trailingZeroes(int n) {
    //     int count = 0;
    //     int divisor = 5;
    //     while(divisor <= n){
    //         count += floor(n/divisor);
    //         divisor *= 5;
    //     }
    //     return count;
    // }
    
};