# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        def get_sum(root, is_left):
            if not root:
                return 0
            
            if not root.left and not root.right:
                if is_left:
                    return root.val
                else:
                    return 0
            
            res = 0
            res += get_sum(root.left, True)
            res += get_sum(root.right, False)
            
            return res
        
        if not root:
            return 0
        
        return get_sum(root.left, True) + get_sum(root.right, False)