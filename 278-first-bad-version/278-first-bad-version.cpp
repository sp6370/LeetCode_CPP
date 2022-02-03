// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 1;
        int end = n;
        int mid = 0;
        while(start<=end)
        {
            mid = start + (end-start)/2;
            
            // int prev = (n + mid - 1)%n+1;
            // int next = (mid + 1)%n+1;
            int prev = mid-1;
            int next = (mid + 1);
            
            if(isBadVersion(prev) == false && isBadVersion(next) == false)
            {
                start = mid+1;
                continue;
            }
            
            if(isBadVersion(prev) == true && isBadVersion(next) == true)
            {
                end = mid - 1;
                continue;
            }
            
            if(isBadVersion(mid) == false)
            {
                return mid+1;
            }
            else
            {
                break; 
            }
            
            
        }
        return mid;
    }
};