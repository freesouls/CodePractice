# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {integer} k
    # @return {integer}
    def __init__(self):
        self.num = 0
        self.count = 0
        self.k = -1
        self.flag = True

    def kthSmallest(self, root, k):
        self.k = k
        self.count = 0
        self.inorder(root)
        return self.num

    def inorder(self, root):
        if root and self.flag:
            if root.left:
                self.inorder(root.left)
            self.count += 1
            if self.count == self.k:
                self.num = root.val
                self.flag = False
                return
            if root.right:
                self.inorder(root.right)
