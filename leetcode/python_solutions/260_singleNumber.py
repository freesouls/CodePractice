class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def singleNumber(self, nums):
        if len(nums) == 0:
            return []

        res = 0

        for num in nums:
            res = res^num
        k = -1
        for i in xrange(0, 32):
            if ((res >> i)&1) == 1:
                k = i
                break

        a = 0
        b = 0

        for num in nums:
            if ((num >> k)&1) == 1:
                a = a^num
            else:
                b = b^num

        return [a, b]
