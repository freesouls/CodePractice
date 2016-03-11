class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string s1, string s2) {
        // Write your code here
        if (s1.length() != s2.length()) {
            return false;
        }

        if (s1 == s2) {
            return true;
        }

        int cnt1[26] = {0};
        // int cnt2[26] = {0};

        int is_equal = 0;

        for (int i = 0; i < s1.length(); i++) {
            cnt1[s1[i] - 'a']++;
            cnt1[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != 0) {
                return false;
            }
        }

        for (int i = 1; i < s1.length(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))&&isScramble(s1.substr(i), s2.substr(i))){
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s1.length()-i))&&isScramble(s1.substr(i), s2.substr(0, s1.length()-i))){
                return true;
            }

        }
        return false;
    }
};
