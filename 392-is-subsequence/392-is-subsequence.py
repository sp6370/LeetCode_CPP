class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if(len(s) == 0):
            return True
        
        if(len(s) != 0 and len(t) == 0):
            return False
        
        sPtr = 0
        
        for i in t:
            if i == s[sPtr]:
                sPtr+=1
                if(sPtr == len(s)):
                    break
        
        if(sPtr == len(s)):
            return True
        
        return False