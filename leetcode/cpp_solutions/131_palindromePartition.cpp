class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        res.clear();
        if (s.length() == 0){
            return res;
        }

        vector<string> p;
        partition(p, s, 0);
        return res;
    }

    void partition(vector<string> p, string& s, int start){
        if (start >= s.length()){
            // for (int i = 0; i < p.size(); i++) {
            //     cout << p[i] << " ";
            // }
            // cout << endl;
            res.push_back(p);
            return;
        }

        for (int i = 1; i <= s.length() - start; i++){
            string tmp = s.substr(start, i);
            if (isPalindrome(tmp)){
                p.push_back(tmp);
                partition(p, s, start + i);
                p.pop_back();
            }
        }
    }

    inline bool isPalindrome(string& s) {
        int i = 0;
        int j = s.length() - 1; // in this example the s.length() will always >= 1

        while(i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

};

/* version 2
class Solution {
public:
    vector<vector<string>> res;
    string ss;
    vector<vector<string>> partition(string s) {
        res.clear();
        if (s.length() == 0){
            return res;
        }
        ss = s;
        vector<string> p;
        partition(p, 0);
        return res;
    }

    void partition(vector<string> p, int start){
        if (start >= ss.length()){
            // for (int i = 0; i < p.size(); i++) {
            //     cout << p[i] << " ";
            // }
            // cout << endl;
            res.push_back(p);
            return;
        }

        for (int i = 1; i <= ss.length() - start; i++){
            if (isPalindrome(start, start + i - 1)){
                p.push_back(ss.substr(start, i));
                partition(p, start + i);
                p.pop_back();
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
