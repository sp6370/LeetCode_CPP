class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
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
        