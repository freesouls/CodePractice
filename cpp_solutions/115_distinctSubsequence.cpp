class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> f(t.size() + 1);
        f[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = t.size() - 1; j >= 0; --j) {
                f[j + 1] += s[i] == t[j] ? f[j] : 0;
            }
        }
        return f[t.size()];
    }
};