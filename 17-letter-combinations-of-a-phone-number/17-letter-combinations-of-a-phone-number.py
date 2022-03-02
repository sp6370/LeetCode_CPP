class Solution(object):    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        digitMapping = {
            "2": ["a","b","c"],
            "3": ["d","e","f"],
            "4": ["g","h","i"],
            "5": ["j","k","l"],
            "6": ["m","n","o"],
            "7": ["p", "q","r","s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"]
        }
        
        
        def permutateString(digits, mapping):
            if(len(digits) == 0):
                return []

            prevResult = permutateString(digits[1:], mapping)
            if(len(prevResult) == 0):
                prevResult.append("")

            result = []

            for q in mapping[digits[0]]:        
                for i in prevResult:
                    result.append(q+i)

            return result
        
        return permutateString(digits, digitMapping)
        