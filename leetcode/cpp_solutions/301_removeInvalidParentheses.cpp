class Solution {
    set<string> res;
    int max_len;
public:

    vector<string> removeInvalidParentheses(string s) {

        int left_removed = 0;
        int right_removed = 0;
        for (char ch : s) {
            if (ch == '(') {
                left_removed++;
            }
            else if (ch == ')') {
                if (left_removed > 0) {
                    left_removed--;
                }
                else {
                    right_removed++;
                }
            }
        }

        string path("");
        dfs(s, 0, path, left_removed, right_removed, 0);

        return vector<string>(res.begin(), res.end());
    }

    void dfs(string& s, int index, string path, int left_removed, int right_removed, int pair) {
        if (index == s.length() && left_removed == 0 && right_removed == 0 && pair == 0) {
            res.insert(path);
        }

        if (index < s.length()) {
            if (s[index] == '(') {
                if (left_removed > 0) {
                    dfs(s, index+1, path, left_removed-1, right_removed, pair);
                }
                // else {
                dfs(s, index+1, path+s[index], left_removed, right_removed, pair+1);
                // }
            }
            else if (s[index] == ')') {
                if (right_removed > 0) {
                    dfs(s, index+1, path, left_removed, right_removed-1, pair);
                }
                if (pair > 0) {
                    dfs(s, index+1, path+s[index], left_removed, right_removed, pair-1);
                }
            }
            else {
                dfs(s, index + 1, path + s[index], left_removed, right_removed, pair);
            }
        }
    }
};


class Solution {
    set<string> res;
    int max_len;
public:
    bool isValid(string s) {
        stack<char> charStack;
        int i = 0;

        while(i != s.length()) {
            char c = s[i];
            if (c != ')') {
                charStack.push(c);
            }
            else {
                if (charStack.size()==0) {
                    return false;
                }
                char pre = charStack.top();
                switch(c) {
                case ')':
                    if (pre == '(')
                      charStack.pop();
                    else
                      return false;
                    break;
                }
            }
            ++i;
        }
        if (charStack.size() == 0)
            return true;
        else
            return false;
    }

    vector<string> removeInvalidParentheses(string s) {
        // res.clear();
        max_len = 0;
        stack<char> st;
        string p("");
        dfs(s, 0, p);
        vector<string> tt;
        for (string ss : res) {
            tt.push_back(ss);
        }
        return tt;
    }

    void dfs(string& s, int index, string p) {
        if (s.length() - index + p.length() < max_len) {
            return ;
        }
        if (index < s.length()) {
            if (s[index] == '(' || s[index] == ')') {
                dfs(s, index + 1, p + s[index]);
                dfs(s, index + 1, p);
            }
            else{
                p.push_back(s[index]);
                dfs(s, index + 1, p);
            }
        }
        else {
            if (p.length() < max_len) {
                return;
            }
            if (isValid(p)) {
                if (p.length() > max_len) {
                    max_len = p.length();
                    res.clear();
                    res.insert(p);
                }
                else if (p.length() == max_len) {
                    res.insert(p);
                }
            }
        }

    }
};
