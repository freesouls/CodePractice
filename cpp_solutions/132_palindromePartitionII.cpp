class Solution {
public:
    int minCut(string s) {
        if (s.length() == 0){
            return 0;
        }
        int len = s.length();
        int cuts[len + 1];
        for(int i = 0; i <= len; i++){
            cuts[i] = len - i;
        }
        vector<bool> tmp(len, false);
        vector<vector<bool>> p(len, tmp);

        for (int i = len - 1; i >= 0; i--){
            for (int j = i; j < len; j++){
                if (s[i]==s[j] && (j - i < 2 || p[i+1][j-1])){
                    p[i][j] = true;
                    cuts[i] = min(cuts[i], 1 + cuts[j + 1]);
                }
            }
        }
        return cuts[0] - 1;
    }
};

/* time exceed
class Solution {
public:
    int res = 0;
    string ss;
    int minCut(string s) {
        res = 0;
        if (s.length() == 0){
            return res;
        }
        ss = s;
        res = s.length() - 1;
        partition(0, 0);
        return res;
    }

    void partition(int start, int cut){
        if (start >= ss.length()){
            res = min(res, cut);
            return;
        }

        if (isPalindrome(start, ss.length() - start - 1)){
            res = min(res, cut);
            return;
        }
        else{
            for (int i = ss.length() - start - 1; i>=1; i--){
                if (isPalindrome(start, start + i - 1)){
                    //p.push_back(ss.substr(start, i));
                    partition(start + i, cut + 1);
                    //p.pop_back();
                }
            }
        }

    }

    inline bool isPalindrome(int i, int j) {
        while(i < j){
            if (ss[i] != ss[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
*/
