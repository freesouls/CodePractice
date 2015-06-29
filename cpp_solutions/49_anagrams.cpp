// TODO: a nice algorithm, not sort first
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <= 1) {
            return res;
        }
        map<string, int> anagram;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end()); // it cost time
            if (anagram.find(s) == anagram.end()) {
                anagram.insert(make_pair(s, i));
            } else {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
