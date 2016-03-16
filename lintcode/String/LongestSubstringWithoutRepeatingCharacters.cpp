class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int index[256];
        memset(index, -1, sizeof(int)*256);
        int max_len = 0;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (index[s[i]] >= j) {
                j = index[s[i]] + 1;
            }
            max_len = std::max(max_len, i - j + 1);
            index[s[i]] = i;
        }

        return max_len;
    }

    int lengthOfLongestSubstring2(string s) {
        // write your code here
        int index[256];
        memset(index, -1, sizeof(int)*256);
        int max_len = 0;
        int j = 0;
        int i = 0;
        for (; i < s.length(); i++) {
            if (index[s[i]] == -1) {
                index[s[i]] = i;
                max_len = std::max(max_len, i - j + 1);
            }
            else {
                if (index[s[i]] >= j) {
                    j = index[s[i]] + 1;
                }
                max_len = std::max(max_len, i - j + 1);
                index[s[i]] = i;
            }
        }

        return max_len;
    }
};
