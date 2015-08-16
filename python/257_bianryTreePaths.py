# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        res = []
        if root is None:
            return res
        tmp = str(root.val)
        if root.left or root.right:
            self.getPaths(root.left, res, tmp)
            self.getPaths(root.right, res, tmp)
        else:
            res.append(tmp)
        return res

    def getPaths(self, root, res, path):
        if root is None:
            return
        else:
            tmp = path + '->' + str(root.val)
            if root.left is None and root.right is None:
                res.append(tmp)
            else:
                self.getPaths(root.left, res, tmp)
                self.getPaths(root.right, res, tmp)

    
