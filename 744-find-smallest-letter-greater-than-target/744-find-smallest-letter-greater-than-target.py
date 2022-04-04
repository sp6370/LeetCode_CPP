class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        start = 0
        end = len(letters) - 1
        result = letters[start]
        
        while start <= end:
            mid = (start+end)//2
            
            if letters[mid] > target:
                result = letters[mid]
                end = mid - 1
            else:
                start = mid + 1
        
        return result
        