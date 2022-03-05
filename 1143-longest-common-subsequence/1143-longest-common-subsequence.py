class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        def solveLCS(str1, str2):    
            dp = [ [0 for i in range(len(str2)+1)] for q in range(len(str1)+1) ]
            
            for i in range (1,len(str1)+1):
                for j in range(1,len(str2)+1):
                    if(str1[i-1] == str2[j-1]):
                        dp[i][j] = 1 + dp[i-1][j-1]
                    else:
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            
            return dp[len(str1)][len(str2)]
        
        return solveLCS(text1, text2)