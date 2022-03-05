class Solution:
    def numSquares(self, n: int) -> int:
        dp = {}
        
        def solveSquares(n):
            square_nums = [i**2 for i in range(0, int(math.sqrt(n))+1)]
            dp = [sys.maxsize for i in range(n+1)]
            dp[0] = 0    
            for i in range(1, n+1):
                for sVal in square_nums:
                    if i<sVal:
                        break
                    dp[i] = min(dp[i], dp[i - sVal]+1)
            return dp[n]
        
        return solveSquares(n)
        