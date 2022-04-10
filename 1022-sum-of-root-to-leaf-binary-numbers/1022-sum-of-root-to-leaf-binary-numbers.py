# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        sum_binary = 0
        state = 0
        def dfs(root, state):
            nonlocal sum_binary
            if not root:
                return
            state = (state << 1) | root.val
            
            if root.left == None and root.right == None:
                sum_binary +=state
                return
            
            dfs(root.left, state)
            dfs(root.right, state)
            return
        
        dfs(root, state)
        return sum_binary
                
                
        