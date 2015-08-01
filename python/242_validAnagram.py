class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False

        a = list(s)
        a.sort()
        b = list(t)
        b.sort()
        return a == b


    def isAnagram1(self, s, t):
        if len(s) != len(t):
            return False
        count = [0]*256
        for char in s:
            count[ord(char)] += 1
        for char in t:
            count[ord(char)] -= 1
            if (count[ord(char)] < 0):
                return False
        for x in count:
            if x > 0:
                return False
        return True
        
