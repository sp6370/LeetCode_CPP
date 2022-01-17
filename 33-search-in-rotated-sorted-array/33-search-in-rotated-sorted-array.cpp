class Solution {
public:
    int bSearch(vector<int> nums, int start, int end, int target)
    {
        if(start>end || start == -1)
        {
            return -1;
        }
        
        int mid = start + (end - start)/2;
        
        if(nums[mid] == target)
        {
            return mid;
        }
        
        if(nums[mid]>target)
        {
            return bSearch(nums, start, mid-1, target);
        }
        
        return bSearch(nums, mid+1, end, target);
    }
    
    int mBinarySearch(vector<int> nums, int start, int end)
    {
        int N = nums.size();
        int ans = -1;
        
        while(start<=end)
        {
            int mid = start + (end - start)/2;
            
            int prev = (mid - 1 + N)%N;
            int next = (mid + 1)%N;
            
            if(nums[mid]<nums[prev] && nums[mid]<nums[next])
            {
                ans = mid;
                break;
            }
            
            if(nums[0]<=nums[mid])
            {
                start = mid + 1;
                
            }
            else
            {
                end = mid - 1;
            }
        }
        
        return ans;
    }
    
    int search(vector<int>& nums, int target) {
        
        //first let's find location of the min element in array
        
        int start = 0;
        int end = nums.size()-1;
        
        int N = nums.size();
        
        // only one element in array
        if(N == 1)
        {
            if(nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        
        //Array is not rotated
        if(nums[start]<nums[end])
        {
            return bSearch(nums, start, end, target);
        }
        
        //find index of smallest element after rotation
        int sPos = mBinarySearch(nums, start, end);
        
        //now binary search in to correct section of the array
        if(target>=nums[0])
        {
            return bSearch(nums, start, sPos-1, target);
        }

        return bSearch(nums, sPos, end, target);;
        
    }
};