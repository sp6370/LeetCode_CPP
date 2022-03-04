# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        
        def getMinDepth(root):
            if(root == None):
                return 0   
            
            if(root.left != None and root.right != None):
                val = 1 + min(getMinDepth(root.left), getMinDepth(root.right))
                return val
            
            if(root.left != None):
                return 1 + getMinDepth(root.left)
            else:
                return 1 + getMinDepth(root.right)
        
        return getMinDepth(root)