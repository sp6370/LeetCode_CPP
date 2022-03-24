import sys

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        # Brute Force
        maxSum = -sys.maxsize -1
        for i in range(len(nums)):
            #start of the array
            for j in range(i, len(nums)):
                # end of the array
                tmpSum = 0
                for q in range(i, j+1):
                    #actually go till the end position 'j' of the array
                    tmpSum+=nums[q]
                maxSum = max(maxSum, tmpSum)
        return maxSum
    
        Time Complexity: O(n^3)"""
        
        """
        # Brute Force
        maxSum = -sys.maxsize - 1
        
        for i in range(len(nums)):
            currSum = 0
            for j in range(i, len(nums)):
                #generate sum: sum of nums[i,j] = sums[i, j-1] + nums[j]
                currSum = currSum + nums[j]
                maxSum = max(maxSum, currSum)
        return maxSum
        Time Complexity: O(n^2)
        """
        
        # Optimal Solution: Kadane's Algo: DP
        # Time Complexity: O(n)
        
        #set up continuous sub-arraysum and maxSum
        currSum = bestSum = nums[0]
        for val in nums[1:]:
            # current sum has the cases: 
            # 1. currSum is negative and val is positive => Val is new currSum
            # 2. both currSum and Val are positive => currSum + val is new currSum
            # 3. currSum is positive and val is negative => currSum - val is new currSum : taken care through max with best sum
            # 4. both currSum and val are negative => val is the new currSum
            currSum = max(val, currSum+val)
            bestSum = max(bestSum, currSum)
        return bestSum
    
        