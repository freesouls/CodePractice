class Solution:
    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):
        n = len(input)
        if n == 0:
            return []
        nums = []
        ops = []
        i = 0

        while i < n:
            if input[i]>='0' and input[i] <= '9':
                start = i
                while i < n and input[i]>='0' and input[i] <= '9':
                    i = i + 1
                nums.append(int(input[start:i]))
            else:
                ops.append(input[i])
                i = i + 1

        # while i < n:
        #     if input[i]>='0' and input[i] <= '9':
        #         tmp = 0
        #         while i < n and input[i]>='0' and input[i] <= '9':
        #             tmp = tmp*10 + int(input[i])
        #             i = i + 1
        #         nums.append(tmp)
        #     else:
        #         ops.append(input[i])
        #         i = i + 1

        return self.getVec(nums, ops, 0, len(nums) - 1)
    def getVec(self, nums, ops, s, e):
        if s == e:
            return [nums[s]]
        res = []
        for i in xrange(s, e):
            a = self.getVec(nums, ops, s, i)
            b = self.getVec(nums, ops, i+1, e)
            for j in xrange(len(a)):
                for k in xrange(len(b)):
                    if ops[i] == '+':
                        res.append(a[j]+b[k])
                    elif ops[i] == '-':
                        res.append(a[j]-b[k])
                    else:
                        res.append(a[j]*b[k])
        return res
