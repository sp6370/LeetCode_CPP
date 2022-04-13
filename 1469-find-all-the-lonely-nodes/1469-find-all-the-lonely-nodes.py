# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        
        def find_nodes(root, is_only_child):
            
            if not root:
                return []
            
            res = []
            if is_only_child:
                res = [root.val]
            
            if root.left and root.right:
                res += find_nodes(root.left, False)
                res += find_nodes(root.right, False)
                return res
            
            if not root.left:
                res += find_nodes(root.right, True)
            else:
                res += find_nodes(root.left, True)
            return res
        
        return find_nodes(root, False)
                
        