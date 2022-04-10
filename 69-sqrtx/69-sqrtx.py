class Solution:
    def mySqrt(self, x: int) -> int:
        
        if x < 2:
            return x
        
        start = 0
        end = x//2
        
        while start <=end:
            mid = (start + end) // 2
            
            if mid * mid == x:
                return int(mid)
            
            if mid*mid > x:
                end = mid - 1
            else:
                start = mid + 1
        
        return int(end)
        