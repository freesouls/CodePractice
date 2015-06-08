class Solution {
public:
    int mySqrt(int x) {
        if ( x <= 0) return 0;
        //return (int)sqrt(x);
        double y = 1;
        double lasty = 0;
        while((int)y != (int)lasty){
            lasty = y;
            y = (y + x / y)/2.0;
        }
        return (int)y;
    }
    
    double sqrt(double x){
        if ( x <= 0.0) return 0.0;
        double y = 1;
        double lasty = 0;
        while(abs(y - lasty) > 0.000000001){
            lasty = y;
            y = (y + x / y)/2.0;
        }
        return y;
    }
};