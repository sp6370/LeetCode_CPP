class Solution:
    def findMin(self, arr: List[int]) -> int:
        # A) IS IT NECESSARY THAT THE ARRAY WOULD BE ROTATED
        # B) WHAT IF THE VALUES ARE REPEATED INSIDE THE ARRAY

        start = 0
        end = len(arr) - 1

        # MANAGING A
        if arr[start] < arr[end]:
            return arr[0]

        result = 0
        comp = arr[0]



        while start <= end:
            mid = (start+end)//2

            # WHY IS EQUAL TO REQUIRED IN LINE 33 => We want to handle the case when mid is 0 
            # i.e equivalent to the comp value
            # or else we would we stuck indide a infinite loop 

            # Confused: I think this not correct we want to have pure true and false boundary
            # the above logic voilates it.

            # As for the infinite loop: Even if we have just the one value 
            # OR repeated comparator values,the index would we updated inside the else,
            # and we would skip the loop in the next iteration.

            # MANAGING B
            if arr[mid] < comp:
                end = mid - 1
                result = mid
            else:
                start = mid + 1

        return arr[result]