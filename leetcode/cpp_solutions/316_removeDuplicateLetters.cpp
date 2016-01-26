class Solution {
public:
    // a variation of problem 321 in getNumber
    string removeDuplicateLetters(string s) {
        // int letter_to_bit[26];
        // int str_bits = 0;
        int letter_count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // str_bits |= letter_to_bit[s[i]-'a'];
            letter_count[s[i]-'a'] += 1;
        }

        int k = 0;
        for (int i = 0; i < 26; i++) {
            if (letter_count[i] > 0) {
                k++;
            }
        }

        int to_drop = s.size() - k;
        string res = "";
        int inserted[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            while(to_drop > 0 && res.size() != 0 && res.back() > s[i] && inserted[s[i]-'a'] != 1 && letter_count[res.back()-'a'] > 1) {
                to_drop--;
                letter_count[res.back()-'a']--;
                inserted[res.back()-'a']--;
                res.pop_back();
            }

            if (inserted[s[i]-'a'] == 1) {
                to_drop--;
                letter_count[s[i]-'a']--;
            }
            else{
                res.push_back(s[i]);
                inserted[s[i]-'a']++;
            }
        }

        return res.substr(0, k);
    }
};
