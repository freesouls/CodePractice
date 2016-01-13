class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0){
            return 0;
        }
        long count = 0;
        long factor = 1;
        long lower = 0, cur = 0, higher = 0;
        while(n/factor != 0){
            lower = n - (n / factor)*factor;
            cur = (n/factor)%10;
            higher = n/(factor*10);
            switch(cur){
                case 0:
                    count += higher*factor;
                    break;
                case 1:
                    count += higher*factor + lower + 1;
                    break;
                default:
                    count += (higher + 1)*factor;
                    break;
            }
            factor *= 10;
        }
        return count;
    }
};
