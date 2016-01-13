class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):

        n = len(s)
        if n <= 1:
            return s
        maxLen = 1
        begin = 0

        for i in xrange(n-1):
            left = i - 1
            right = i + 1
            while left >= 0 and s[left]==s[i]:
                left -= 1
            while right < n and s[right]==s[i]:
                right += 1
            l = right - left - 1

            while left>=0 and right<len(s) and s[left] == s[right]:
                l += 2
                left -= 1
                right += 1

            if l > maxLen:
                begin = left + 1
                maxLen = l

        return s[begin:begin+maxLen]

    def longestPalindrome1(self, s):

        n = len(s)
        if n <= 1:
            return s
        maxLen = 1
        begin = 0

        for i in xrange(n-1):
            b, l = self.get(s, i, i)
            if l > maxLen:
                begin = b
                maxLen = l
            b, l = self.get(s, i, i+1)
            if l > maxLen:
                begin = b
                maxLen = l
        return s[begin:begin+maxLen]

    def get(self, s, left, right):
        l = 0
        while left>=0 and right<len(s) and s[left] == s[right]:
            if left == right:
                l += 1
            else:
                l += 2
            left -= 1
            right += 1

        return left+1, l
