from functools import lru_cache

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        @lru_cache(maxsize=None)
        def solver(str1, str2):
            if(len(str1) == 0 or len(str2) == 0):
                return 0
            
            if(str1[0] == str2[0]):
                return 1 + solver(str1[1:], str2[1:])
            
            a = solver(str1[1:], str2[1:])
            b = max(solver(str1, str2[1:]), solver(str1[1:],str2))
            return max(a,b)
        
        return solver(text1, text2)
