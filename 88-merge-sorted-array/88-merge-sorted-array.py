import copy
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        Easy Appraoch: Just put them together and sort nums1
        """
        # for i in range(n):
        #     nums1[m+i] = nums2[i]
        # nums1.sort()
        
        """
        Using 3 pointer along with extra space
        """
        copy_nums1 = copy.deepcopy(nums1[:m])
        
        read_copy = 0
        read_nums2 = 0
        write_nums1 = 0
        
        for i in range(m+n):
            if (read_nums2 >=n) or (read_copy < m and copy_nums1[read_copy] < nums2[read_nums2]):
                nums1[i] = copy_nums1[read_copy]
                read_copy+=1
            else:
                nums1[i] = nums2[read_nums2]
                read_nums2+=1
        
        
        
        