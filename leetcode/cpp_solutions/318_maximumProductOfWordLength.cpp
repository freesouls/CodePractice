class Solution {
public:
    int maxProduct(vector<string>& words) {
        // vector<int> letter_to_bit(26, 0);
        int n = words.size();
        int letter_to_bit[26];
        for (int i = 0; i < 26; i++) {
            letter_to_bit[i] = 1<<i;
        }

        int word_to_bits[n];
        int word_length[n];
        for (int i = 0; i < n; i++) {
            int res = 0;
            word_length[i] = words[i].size();
            for (int j = 0; j < word_length[i]; j++) {
                res |= letter_to_bit[words[i][j]-'a'];
            }
            word_to_bits[i] = res;
        }

        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((word_to_bits[i]&word_to_bits[j]) == 0) {
                    int len = word_length[i]*word_length[j];
                    if (len > max_len) {
                        max_len = len;
                    }
                }
            }
        }
        return max_len;
    }
};
