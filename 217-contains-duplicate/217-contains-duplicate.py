class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        dataDict = {}
        
        for i in nums:
            if i in dataDict:
                return True
            else:
                dataDict[i] = 1
        
        return False
        