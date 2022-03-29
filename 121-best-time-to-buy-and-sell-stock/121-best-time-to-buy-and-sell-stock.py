import sys

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = sys.maxsize
        max_profit = 0
        
        for i in prices:
            if i < min_price:
                min_price = i
            else:
                max_profit = max(i - min_price, max_profit)
        
        return max_profit
        