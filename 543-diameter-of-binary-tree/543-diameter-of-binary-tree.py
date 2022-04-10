# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = 0
        
        def find_diameter(root):
            if not root:
                return 0
            
            nonlocal diameter
            
            left_result = find_diameter(root.left)
            right_result = find_diameter(root.right)
            
            curr_diamtr = left_result + right_result
            diameter = max(curr_diamtr, diameter)
            
            return 1 + max(left_result, right_result)
        
        find_diameter(root)
        return diameter
            
        