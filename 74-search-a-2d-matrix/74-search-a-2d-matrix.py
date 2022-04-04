class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
       
        def findBoundary(data: List[int], target:int) -> int:
            start = 0
            end = len(data) - 1
            result = -1
            while start <= end:
                mid = (start + end) // 2
                if data[mid] <= target:
                    result = mid 
                    start = mid + 1
                else:
                    end = mid - 1
            return result
        
        def bSearch(data, target):
            start = 0
            end = len(data) - 1
            while start<=end:
                mid = (start + end) // 2
                if data[mid] == target:
                    return True
                elif data[mid] > target:
                    end = mid - 1
                else:
                    start = mid + 1
            return False
                
        # FIND THE ROW NUMBER WITH GREATEST NUMBER SMALLER THAN THE TARGET
        r = len(matrix)
        c = len(matrix[0])
        first_col_data = []
        for i in range(r):
            first_col_data.append(matrix[i][0])
        target_row = findBoundary(first_col_data, target)
        
        # CHECK FOR THE VALUE IN THE TARGET ROW
        if target_row == -1:
            return bSearch(matrix[0], target)
        else:
            return bSearch(matrix[target_row], target)
        
        