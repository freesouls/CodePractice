# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import Queue
class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        q = Queue.Queue()
        if root:
            q.put(root)
        while not q.empty():
            node = q.get()
            tmp = node.left
            node.left = node.right
            node.right = tmp
            if node.left:
                q.put(node.left)
            if node.right:
                q.put(node.right)
        return root

    # def invertTree(self, root):
    #     if root:
    #         tmp = root.left
    #         root.left = root.right
    #         root.right = tmp
    #         self.invertTree(root.left)
    #         self.invertTree(root.right)
    #     return root
