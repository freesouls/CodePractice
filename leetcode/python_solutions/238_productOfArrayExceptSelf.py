class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        n =  len(nums)
        before = 1
        res = [1]*n;
        # for i, num in enumerate(nums):
        #     res[i] *= before
        #     before *= num
        for i in xrange(0, n):
            res[i] *= before
            before *= nums[i]
        after = 1
        i = n - 1
        while(i >= 0):
            res[i] *= after
            after *= nums[i]
            i -= 1
        return res
