class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        #Sorting doesn't work
        """
        nums.sort()
        left = 0
        right = len(nums)-1
        while(left <= right):
            if(nums[left]+nums[right] == target):
                return [left, right]
            elif(nums[left]+nums[right] < target):
                left+=1
            else:
                right-=1"""
        
        data = {}
        count = 0 
        for i in nums:
            key = target-i
            if key in data:
                return [data[key], count]
            else:
                data[i] = count
            count+=1
        