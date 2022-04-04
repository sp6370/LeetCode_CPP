class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        start = 0
        end = len(arr) - 1
        result = -1
        
        while start <=end :
            mid = (start+end)//2
            if arr[mid] > arr[mid + 1]:
                result = mid
                end = mid - 1
            else:
                start = mid + 1
        
        return result
        