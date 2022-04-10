# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        def find_diameter(root):
            if not root:
                return (0, 0)
            
            left_result = find_diameter(root.left)
            right_result = find_diameter(root.right)
            
            curr_diameter = left_result[0] + right_result[0]
            curr_height = 1 + max(left_result[0], right_result[0])
            
            max_sub_dia = max(left_result[1], right_result[1])
            
            return (curr_height, max(curr_diameter, max_sub_dia))
        
        return find_diameter(root)[1]
            
        