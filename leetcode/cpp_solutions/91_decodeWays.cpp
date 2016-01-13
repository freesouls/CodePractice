class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0'){
            return 0;
        }
        int n = s.length();
        int pre = 1;
        int cur = 1;

        for (int i = 1; i < n; i++){
            if (s[i] == '0'){
                cur = 0;
            }

            if (!(s[i-1] == '1'|| (s[i-1] == '2'&& s[i] <= '6'))){
                pre = 0;
            }
            if (!pre && !cur){ // stop if pre == cur == 0
                return 0;
            }
            int tmp = cur;
            cur += pre;
            pre = tmp;

        }
        return cur;
    }
};

/* version 2
class Solution {
public:
    // similar to climbing stairs
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0'){
            return 0;
        }
        int n = s.length();
        int pre = 0;
        int cur = 1;

        for (int i = 0; i < n; i++){
            if (s[i] == '0'){
                cur = 0;
            }

            if (i>0 && !(s[i-1] == '1'|| (s[i-1] == '2'&& s[i] <= '6'))){
                pre = 0;
            }
            int tmp = cur;
            cur += pre;
            pre = tmp;

        }
        return cur;
    }
};
*/
