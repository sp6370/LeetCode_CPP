from collections import defaultdict

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = right = max_win_size = 0
        window = defaultdict(int)
        n = len(nums)
        
        for right in range(n):
            
            val = nums[right]
            
            if val is 1:
                window[val] += 1
                # assumption windows is valid every time at this point
            else:
                #val is 0
                window[val] += 1

                while left <= right and window[0] > k:           
                    window[nums[left]] -= 1
                    left += 1

            max_win_size = max(max_win_size, window[0] + window[1])
        
        return max_win_size
            