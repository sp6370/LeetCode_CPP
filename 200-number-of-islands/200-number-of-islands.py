class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        R = len(grid)
        C = len(grid[0])

        seen = [[False for i in range(C)] for j in range(R)]
        num_islands = 0
        neighbours = [(1,0), (-1,0), (0,1), (0,-1)]
        
        for curr_r in range(R):
            for curr_c in range(C):
                if grid[curr_r][curr_c] == "1" and not seen[curr_r][curr_c]:
                    
                    stack = [(curr_r, curr_c)]
                    seen[curr_r][curr_c] = True
                    num_islands+=1
                    
                    while stack:
                        r, c = stack.pop()
                        for nr, nc in neighbours:
                            nei_r = r + nr 
                            nei_c = c + nc
                            
                            neir_r_in_bound = nei_r in range(R)
                            neir_c_in_bound = nei_c in range(C)
                            
                            if neir_r_in_bound and neir_c_in_bound:
                                if grid[nei_r][nei_c] == "1" and not seen[nei_r][nei_c]:
                                    stack.append((nei_r, nei_c))
                                    seen[nei_r][nei_c] = True
                                    
        return num_islands
                            
        
        
        