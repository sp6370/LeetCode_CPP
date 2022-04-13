# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        
        def get_trees(root1, root2):
            
            if not root1 and not root2:
                return None
            
            if root1 and root2:
                root1.val = root1.val + root2.val
                root1.left = get_trees(root1.left, root2.left)
                root1.right = get_trees(root1.right, root2.right)
                return root1
            
            if not root1:
                return root2
            
            if not root2:
                return root1
        
        return get_trees(root1, root2)