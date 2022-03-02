#User function Template for python3
class Solution:
	def minSteps(self, N):
		state = {}
		def helper(N, state):
		    if(N == 1):
		        return 0
            
            if(N in state):
                return state[N]
            
            result = helper(N-1, state)
            
            if(N%2 == 0):
                result = min(result, helper(N/2, state))
            
            if(N%3 == 0):
                result = min(result, helper(N/3, state))
            
            state[N] = 1 + result
            return state[N]

        return helper(N, state)
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		ob = Solution()
		ans = ob.minSteps(N)
		print(ans)

# } Driver Code Ends