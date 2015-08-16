class Solution:
    # @param {integer} num
    # @return {integer}
    def addDigits(self, num):
        if num == 0:
            return 0
        num = num%9
        if num == 0:
            return 9
        else:
            return num
