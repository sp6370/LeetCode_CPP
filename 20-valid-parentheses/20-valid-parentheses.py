"""
U:
Mock Example - Manual Review
Happy Case: ip: {}{}[{}] => True & ip: {[)} => False
Edge Case:  ip:  Empty Input=> True     

M:
Possible DSA:
Use stack alomg with linear scan

P:
S1: Start reading the array
S2: If opening brace then push
S3: Else If Closing brace and stack top is corresponding opening brace
                then pop stack and continue
         Else: Return False
I: 

R: 

E:
"""


class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {'}':'{', ')':'(', ']':'['}
        stack = []
        for val in s:
            if val not in mapping:
                stack.append(val)
            else:
                if len(stack) and stack[-1] == mapping[val]:
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
            
        
        
        