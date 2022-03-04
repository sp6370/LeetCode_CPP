# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        
        def getAverage(root):
            if(root == None):
                return [0]
            
            levelNodeCount = 1
            childNodeCount = 0
            
            nodeQueue = [root]
            result = []
            levelSum = 0
            
            while(len(nodeQueue) != 0):
                levelCount = levelNodeCount
                
                while(levelNodeCount):
                    cNode = nodeQueue.pop(0)
                    levelSum += cNode.val 
                    if(cNode.left != None):
                        nodeQueue.append(cNode.left)
                        childNodeCount+=1
                    if(cNode.right != None):
                        nodeQueue.append(cNode.right)
                        childNodeCount+=1
                    levelNodeCount-=1
                
                result.append(levelSum/levelCount)
                levelNodeCount = childNodeCount
                childNodeCount = 0
                levelSum = 0
            
            return result
        
        return getAverage(root)
                
    