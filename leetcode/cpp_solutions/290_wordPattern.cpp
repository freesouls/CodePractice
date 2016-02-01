class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> mapper(26, "");
        map<string, int> reverse_mapper;
        int j = 0;
        int str_len = str.length();
        int i = 0;
        for (; i < pattern.length(); i++) {
            if (j >= str_len) {
                break;
            }
            int ch = pattern[i] - 'a';
            int ptr = j;
            while(ptr < str_len && str[ptr] != ' ') {
                ptr++;
            }

            string word = str.substr(j, ptr - j);
            if (mapper[ch] == "") {
                if (reverse_mapper.find(word) != reverse_mapper.end()) {
                    return false;
                }
                reverse_mapper[word] = ch;
                mapper[ch] = word;
            }
            else {
                if (word != mapper[ch]) {
                    return false;
                }
            }
            j = ++ptr;
        }
        if (j < str_len || i < pattern.length()) {
            return false;
        }
        return true;
    }
};
