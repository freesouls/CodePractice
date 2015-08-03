class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        d = {}
        max_len = 0
        left = 0
        for i, ch in enumerate(s):
            if ch in d and d[ch] >= left:
                left = d[ch] + 1
            d[ch] = i
            max_len = max(max_len, i - left + 1)
        return max_len

    def lengthOfLongestSubstring0(self, s):
        # d = {}
        d = [-1]*128
        max_len = 0
        left = 0
        for i, ch in enumerate(s):
            index = ord(ch)
            if d[index] != -1 and d[index] >= left:
                left = d[index] + 1
            d[index] = i
            max_len = max(max_len, i - left + 1)
        return max_len

    def lengthOfLongestSubstring1(self, s):
        cnt = [-1]*128
        max_len = 0
        tmp = 0
        i = 0
        while i < len(s):
            ch = ord(s[i])
            if cnt[ch] == -1:
                cnt[ch] = i
                tmp += 1
            else:
                if tmp > max_len:
                    max_len = tmp
                i = cnt[ch]
                tmp = 0
                cnt = [-1]*128
            i += 1

        return max_len
