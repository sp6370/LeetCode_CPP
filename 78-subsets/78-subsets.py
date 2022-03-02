class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        
        def solver(nums):
            if(len(nums) == 0):
                return []
            
            prevResult = solver(nums[1:])
            
            if(len(prevResult)==0):
                return [[nums[0]], []]
            
            result = []
            
            for i in prevResult:
                result.append([nums[0]]+i)
            
            result = result + prevResult
            return result
        
        return solver(nums)