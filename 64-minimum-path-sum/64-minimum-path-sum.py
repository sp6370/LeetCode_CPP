class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        dp = [ [0 for i in range(len(grid[0]))] for j in range(len(grid))]
        # dp = [[0 for i in range(numCol)] for q in range(numRow)]
        
        def solver(grid, numRows, numCols):
            for i in range(numRows):
                for j in range(numCols):
                    if(i == 0 and j == 0):
                        dp[i][j] = grid[i][j]
                        continue
                    if(i == 0):
                        dp[i][j] = grid[i][j] + dp[i][j-1]
                        continue
                    if(j == 0):
                        dp[i][j] = grid[i][j] + dp[i-1][j]
                        continue
                    dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])
        
        solver(grid, len(grid), len(grid[0]))
        
        return dp[len(grid)-1][len(grid[0])-1]
            
        