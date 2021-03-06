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
        copy_nums1 = copy.deepcopy(nums1[:m])
        
        #read pointers
        read_copy = 0
        read_nums2 = 0      
        for i in range(m+n):
            # First Check: If pointer for nums2 is out of bound auto into first
            # Or
            # Second Check: Nums1copy ptr is not out of bounds and the value is smaller than in the 
            # nums2
            if (read_nums2 >=n) or (read_copy < m and copy_nums1[read_copy] < nums2[read_nums2]):
                nums1[i] = copy_nums1[read_copy]
                read_copy+=1
            else:
                nums1[i] = nums2[read_nums2]
                read_nums2+=1
        """
        
        # Approach 3: Using 3 pointers and no extra space
        # Let's exploit the space available at the end of the array
        
        #read pointers
        p1 = m-1
        p2 = n-1
        
        #write pointer
        p3 = m+n-1
        
        for p3 in range(m+n-1, -1, -1):
            if p2<0 or (p1>=0 and nums1[p1]>nums2[p2]):
                nums1[p3] = nums1[p1]
                p1-=1
            else:
                nums1[p3] = nums2[p2]
                p2-=1
        
        
        
        