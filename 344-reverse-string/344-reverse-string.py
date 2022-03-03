class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        def solver(left, right):
            if(left < right):
                s[left], s[right] = s[right], s[left]
                solver(left+1, right -1 )
        
        solver(0, len(s)-1)