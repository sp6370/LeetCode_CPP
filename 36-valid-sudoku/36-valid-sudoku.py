class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        N = 9
        row_data = [set() for _ in range(9)]
        col_data = [set() for _ in range(9)]
        grid_data = [set() for _ in range(9)]
        
        for r in range(N):
            for c in range(N):
                val = board[r][c]
                
                if val == ".":
                    continue
                
                if val in row_data[r]:
                    return False
                row_data[r].add(val)
                
                if val in col_data[c]:
                    return False
                col_data[c].add(val)
                
                # let's find the grid number
                idx = (c//3) + ((r//3) * 3)
                if val in grid_data[idx]:
                    return False
                grid_data[idx].add(val)
                    
        return True
        

                
            
        