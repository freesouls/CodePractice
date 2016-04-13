class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int index_2 = 0;
        int index_3 = 0;
        int index_5 = 0;

        int num = 1;
        int num_2 = 1;
        int num_3 = 1;
        int num_5 = 1;
        vector<int> res(n, 0);
        int i = 0;
        while(i < n){
            num = min(num_2, min(num_3, num_5));
            res[i] = num;
            i++;
            if (num == num_2) {
                num_2 = res[index_2]*2;
                index_2++;

            }

            if (num == num_3) {
                num_3 = res[index_3]*3;
                index_3++;
            }

            if (num == num_5) {
                num_5 = res[index_5]*5;
                index_5++;
            }
        }
        return res[n-1];
    }
};
