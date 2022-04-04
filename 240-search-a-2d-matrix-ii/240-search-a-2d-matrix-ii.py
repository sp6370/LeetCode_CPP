from bisect import bisect_left

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        def find(a, x):
            i = bisect_left(a, x)
            if i != len(a) and a[i] == x:
                return True
            else: 
                return False

        for i in range(len(matrix)):
            if find(matrix[i], target):
                return True
        
        return False
        
        