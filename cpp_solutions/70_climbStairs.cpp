class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0){
            return 0; 
        }
        
        int f_prev = 0;
        int f = 1;
        int res = 0;
        for (int i = 1; i<=n; i++){
            res = f_prev + f;
            f_prev = f;
            f = res;
        }
        return res;
    }
};