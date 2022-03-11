# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import sys

class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        
        def inTraverse(root):
            if(root == None):
                return []
            
            lans = inTraverse(root.left)
            lans += [root.val]
            lans += inTraverse(root.right)
            
            return lans

        result = inTraverse(root)
        
        minVal = sys.maxsize
        for i in range(1, len(result)):
            minVal = min(minVal, abs(result[i-1] - result[i]))
        
        return minVal
        