class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        result = []
        def find_permutaions(nums, used, path):
            nonlocal result
            if len(path) == len(nums):
                result.append(path[:])
                return
            
            for i in range(len(nums)):
                if used[i]:
                    continue
                
                path.append(nums[i])
                used[i] = True
                
                find_permutaions(nums, used, path)
                
                path.pop()
                used[i] = False
        
        find_permutaions(nums, [False for i in range(len(nums))], [])
        
        return result
            
        