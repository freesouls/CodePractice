class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        dic = {}
        res = []
        for i in xrange(0, len(nums)):
            if nums[i] in dic:
                res.append(dic[nums[i]])
                res.append(i + 1)
                #res = [dic[nums[i]], i]
                return res;
            else:
                dic[target - nums[i]] = i + 1
        return res
        
