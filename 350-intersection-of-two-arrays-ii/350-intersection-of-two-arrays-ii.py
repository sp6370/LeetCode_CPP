class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
        Approach using the hash map extra space
        hash_data_1 = {}
        for i in nums1:
            if i in hash_data_1:
                hash_data_1[i]+=1
            else:
                hash_data_1[i]=1
        
        hash_data_2 = {}
        for i in nums2:
            if i in hash_data_2:
                hash_data_2[i]+=1
            else:
                hash_data_2[i] = 1
        
        result = []
        
        for i in hash_data_2:
            if i in hash_data_1:
                count = min(hash_data_1[i], hash_data_2[i])
                result.extend([i]*count)
        
        return result
        """
        
        """
        Sorting and then doing it using two(three) pointers
        """
        # if not len(nums1) or not len(nums2):
        #     return []
        
        nums1.sort()
        nums2.sort()
        
        print(nums1)
        print(nums2)
        # read pointer 
        p1 = 0
        p2 = 0
        
        result = []
        
        while p1<len(nums1) and p2<len(nums2):
            if nums1[p1] == nums2[p2]:
                result.append(nums1[p1])
                p1+=1
                p2+=1
            elif nums1[p1] < nums2[p2]:
                p1+=1
            else:
                p2+=1
        
        return result