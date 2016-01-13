class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> res(n, 0);
        int f_2 = 2, f_3 = 3, f_5 = 5;
        int i_2 = 0;
        int i_3 = 0;
        int i_5 = 0;


        res[0] = 1;
        int prev = 0;
        int i = 1;
        while(i < n){
            int min = std::min(f_2, std::min(f_3, f_5));
            res[i] = min;
            if (min == f_2) {
                f_2 = 2*res[++i_2];
            }

            if (min == f_3) {
                f_3 = 3*res[++i_3];
            }

            if (min == f_5) {
                f_5 = 5*res[++i_5];
            }

            i++;
        }

        return res[n-1];
    }
};
