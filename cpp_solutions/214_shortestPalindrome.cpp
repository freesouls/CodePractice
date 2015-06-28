class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> p(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && t[i] != t[j]) j = p[j - 1];
            p[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - p[t.size() - 1]) + s;
    }
};
/*
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length() <= 1){
            return s;
        }
        int start = 0;
        int end = s.length() - 1;
        int center = end / 2;
        while(start < end){
            if (isPalindrome(s, start, end)){
                break;
            }
            end--;
        }
        if (end < s.length() - 1){
            string tmp = s.substr(end + 1, s.length() - 1 - end);
            std::reverse(tmp.begin(), tmp.end());
            return tmp + s;
        }
        else{
            return s;
        }
    }

    inline bool isPalindrome(string& ss, int i, int j) {
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
