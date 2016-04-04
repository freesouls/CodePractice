class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if ( n == 0 ) {
            return 1.0;
        }
        if ( n < 0 ) {
            return 1.0/myPow(x, -n);
        }

        double tmp = myPow(x, n/2);
        if ( n % 2 == 0) {
            return tmp*tmp;
        }
        else {
            return tmp*tmp*x;
        }

    }
};
