class Solution {
public:
    string getPermutation(int n, int k) {
        if (n <= 0)
            return "";
        
        string res(n, '0');
        int base = 1;
        vector<int> dic;
        for (int i = 1; i <= n; i++){
            dic.push_back(i);
        }
        
        for (int i = 2; i < n; i++){
            base *= i;
        }
        --k;
        for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
            int quotient = k / base;
            res[n-1-i] += dic[quotient];
            dic.erase(dic.begin() + quotient);
        }
        res[n-1] += dic[0];
        return res;
    }

};