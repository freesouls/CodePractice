class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        string res;
        int len = A.length() - k;
        for (int i = 0; i < A.length(); i++) {
            while(res.length() != 0 && k > 0 && res.back() > A[i]) {
                res.pop_back();
                k--;
            }
            res.push_back(A[i]);
        }
        while(k > 0) {
            res.pop_back();
            k--;
        }

        int i = 0;
        while(res[i] == '0') {
            i++;
        }

        return res.substr(i);

    }
};
