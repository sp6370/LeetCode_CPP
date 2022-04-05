class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        def bSearch(nums, start, end, target):
            result = -1
            while start<=end:
                mid = (start + end) // 2
                if nums[mid] == target:
                    result = mid
                    end = mid -1
                elif nums[mid] >target:
                    end = mid -1
                else:
                    start = mid + 1
            return result
        
        def modBinarySearch(nums, start, end):
            comp = nums[start]
            result = 0
            while start<=end:
                mid = (start + end) //2
                if nums[mid]<comp:
                    result = mid
                    end = mid - 1 
                else:
                    start = mid + 1
            return result
        
        # BOOK KEEPING
        start = 0
        end = len(nums) - 1
        
        # CHECK FOR THE ROTATION
        if nums[0] <= nums[-1]:
            return bSearch(nums, start, end, target)
        
        #FIND THE START OF SMALLEST NUMBER IN THE ARRAY
        rot_idx = modBinarySearch(nums, start, end)
        
        if target < nums[start]:
            return bSearch(nums, rot_idx, end, target)
        else:
            return bSearch(nums, start, rot_idx-1, target)
        
        