# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        sum_binary = 0
        state = ""
        def dfs(root):
            nonlocal state
            nonlocal sum_binary
            if not root:
                return
            state +=str(root.val)
            
            if root.left == None and root.right == None:
                sum_binary += int(state, 2)
                state = state[:-1]
                return
            
            dfs(root.left)
            dfs(root.right)
            
            state = state[:-1]
            return
        dfs(root)
        return sum_binary
                
                
        