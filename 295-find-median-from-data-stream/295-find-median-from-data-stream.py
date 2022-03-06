import heapq
class MaxHeap:
    def __init__(self):
        self.data = []
    
    def push(self, val):
        heapq.heappush(self.data, -val)
        
    def top(self):
        if(len(self.data) == 0):
            return 0
        return -self.data[0]
    
    def pop(self):
        return -heapq.heappop(self.data)
    
    def size(self):
        return len(self.data)

class MedianFinder:

    def __init__(self):
        self.maxA = MaxHeap()
        self.minB = []
        
    def addNum(self, num: int) -> None:
        if(self.maxA.size() == len(self.minB)):
            minEle = num
            if len(self.minB) != 0 and num > self.minB[0]:
                heapq.heappush(self.minB, num)
                minEle = heapq.heappop(self.minB)
            self.maxA.push(minEle)
        else:
            self.maxA.push(num)
            maxEle = self.maxA.pop()
            heapq.heappush(self.minB, maxEle)

    def findMedian(self) -> float:
        # if self.maxA.size() == 0:
        #     return None
        
        if(self.maxA.size() == len(self.minB)):
            return (self.maxA.top() + self.minB[0])/2
        else:
            return self.maxA.top()

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()