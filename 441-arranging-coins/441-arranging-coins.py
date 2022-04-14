class Solution:
    def arrangeCoins(self, n: int) -> int:
        
        def sumK(n):
            a = n * (n+1)
            return a//2
        
        start = 0
        end = n
        result = n
        while start <= end:
            mid = (start + end) // 2
            if sumK(mid) <= n:
                result = mid
                start = mid + 1
            else:
                end = mid - 1
        return result
                
            
        