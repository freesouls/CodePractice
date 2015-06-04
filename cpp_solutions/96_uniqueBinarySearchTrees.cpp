class Solution {
public:
    int numTrees(int n) {
        if (n <= 0){
            return 0;
        }
        if (n == 1 ){
            return 1;
        }

        vector<int> sum;
        sum.resize(n+1);
        sum[0] = 1;
        sum[1] = 1;
        for(int i = 2; i <= n; i++){
            int num = 0;
            for(int j = 1; j <= i; j++){
                num += sum[j-1] * sum[i - j];
            }
            sum[i] = num;
        }
        return sum[n];
    }
};