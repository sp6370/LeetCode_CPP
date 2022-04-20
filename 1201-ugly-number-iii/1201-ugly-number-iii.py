class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        # get LCM's
        ab = (a*b) // gcd(a,b)
        bc = (b*c) // gcd(b,c)
        ca = (c*a) // gcd(c,a)
        abc = (ab*c) // gcd(ab,c)

        Mod = 10**9 + 7

        def get_count(k):
            count = (k//a) + (k//b) + (k//c) - (k//ab) - (k//bc) - (k//ca) + (k//abc)
            return count

        start = min(a,b,c)
        end = n * min(a,b,c)

        result = 0

        while start <= end:

            mid = (start + end) // 2

            if get_count(mid) >= n:
                end = mid - 1
                result = mid
            else:
                start = mid + 1

        return result
        