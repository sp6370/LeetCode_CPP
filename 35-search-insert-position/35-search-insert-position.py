class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        
        if target > nums[end]:
            return end + 1
        
        result = 0
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] >= target:
                result = mid
                end = mid - 1
            else:
                start = mid + 1
        return result