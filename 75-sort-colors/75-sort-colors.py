class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        """
        # let's implement bubble sort
        for i in range(len(nums)-1, -1, -1):
            for j in range(i):
                if nums[j] > nums[j+1]:
                    nums[j], nums[j+1] = nums[j+1], nums[j]
        """
        # simple approach count number of 0, 1, 2
        
        data = {}
        for i in nums:
            if i in data:
                data[i]+=1
            else:
                data[i]=1
                
        for i in range(len(nums)):
            if 0 in data and data[0] > 0:
                nums[i] = 0
                data[0]-=1
            elif 1 in data and data[1] > 0:
                nums[i] = 1
                data[1] -= 1
            else:
                nums[i] = 2
        
        
                