import copy
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        """
        Easy Appraoch: Just put them together in different list and sort it
        """
        for i in range(n):
            nums1[m+i] = nums2[i]
        nums1.sort()
        
        