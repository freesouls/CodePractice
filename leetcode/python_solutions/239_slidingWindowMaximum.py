from collections import deque
class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer[]}
    def maxSlidingWindow(self, nums, k):
        res = []
        q = deque()
        
        for i in xrange(0, len(nums)):
            while(q and nums[q[-1]] <= nums[i]):
                q.pop()
            q.append(i)
            if (i >= k -1):
                if (i > k - 1):
                    while (i - k + 1) > q[0]:
                        q.popleft()
                res.append(nums[q[0]])
        
        return res