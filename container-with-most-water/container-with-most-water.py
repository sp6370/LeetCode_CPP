class Solution:
    def maxArea(self, height: List[int]) -> int:
        # # brute force
        # max_area = 0
        # n = len(height)
        # for i in range(n-1):
        #     for j in range(i+1, n):
        #         area = min(height[i], height[j]) * (j - i)
        #         max_area = max(max_area, area)                
        # return max_area
        
        #Optimal 
        #Assumption: Left and right at setup denote the greatest width possible
        
        left = 0
        right = len(height)-1
        max_area = 0
        while left < right:
            area = min(height[left], height[right]) * (right - left)
            max_area = max(area, max_area)
            
            if height[left] < height[right]:
            # max bang for the byck after decreasing width by 1
                left += 1
            else:
                right -= 1
                
        return max_area