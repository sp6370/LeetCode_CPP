class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        
        m = len(mat)
        n = len(mat[0])
        
        if m*n != r*c:
            return mat
        
        result = [[0 for i in range(c)] for q in range(r)]
        
        index = 0
        
        for i in range(r):
            for j in range(c):
                x = index // n;
                y = index % n;
                result[i][j] = mat[x][y]
                index+=1
        
        return result
        