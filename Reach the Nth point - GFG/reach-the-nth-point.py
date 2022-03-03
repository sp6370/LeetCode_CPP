#User function Template for python3

class Solution:
	def nthPoint(self,n):
	    state = {}
        state[1] = 1
        state[2] = 2
        mod = 10**9+7
        def solver(n, state):
            if(n <= 0):
                state[n] = 1
                return state[n]
    
            if(n in state):
                return state[n]
            
            state[n] = (solver(n-1, state)%mod + solver(n-2, state)%mod)%mod
            return state[n]
        
        return solver(n, state)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution();
		ans = ob.nthPoint(n)
		print(ans)
# } Driver Code Ends