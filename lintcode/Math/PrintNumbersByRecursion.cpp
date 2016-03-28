class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        if (n == 0) {
            return res;
        }
        dfs(res, n);
        res.erase(res.begin());
        return res;
    }

    void dfs(vector<int>& res, int n) {
        if (n == 1) {
            for(int i = 0; i < 10; i++) {
                res.push_back(i);
            }
        }
        else{
            dfs(res, n-1);
            int c_size = res.size();
            for (int i = 1; i < 10; i++) {
                int base = i*pow(10, n-1);
                for (int j = 0; j < c_size; j++) {
                    res.push_back(base + res[j]);
                }
            }
        }
    }
};
