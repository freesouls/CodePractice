class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> res;
        res.resize(digits.size());
        for (int i = digits.size()-1; i>=0; i--){
            c += digits[i];
            res[i] = c % 10;
            c /= 10; 
        }
        if (c > 0){
            res.insert(res.begin(), 1);
        }
        return res;
    }
};