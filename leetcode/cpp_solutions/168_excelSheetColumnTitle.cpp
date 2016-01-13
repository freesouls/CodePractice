class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        n -= 1;
        if (n < 0) return res;
        
        while(n > 25){
            string tmp = string(1, n % 26 + 'A');
            res = tmp + res;
            n /= 26;
            n -= 1;
        }
        
        res = string(1, n % 26 + 'A') + res;
        return res;
    }
};