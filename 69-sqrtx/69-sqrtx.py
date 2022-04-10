class Solution:
    def mySqrt(self, x: int) -> int:
        
        if x < 2:
            return x
        
        start = 0
        end = x
        
        result = -1
        while start <=end:
            mid = (start + end) // 2
            
            if mid*mid <= x:
                result = mid
                start = mid + 1
            else:
                end = mid - 1
        
        return result
        