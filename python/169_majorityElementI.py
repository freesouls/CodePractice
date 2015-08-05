class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        cnt1 = 0
        num1 = 0
        for num in nums:
            if num == num1:
                cnt1 += 1
            elif cnt1 == 0:
                num1 = num
                cnt1 = 1
            else:
                cnt1 -= 1
        return num1
