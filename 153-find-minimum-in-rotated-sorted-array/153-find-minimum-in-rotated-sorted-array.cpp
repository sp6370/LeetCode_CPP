class Solution {
public:
    
    int findMin(vector<int>& nums) {
       
        int start = 0;
        int end = nums.size()-1;
        int N = nums.size();
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        if(nums[start] < nums[end])
        {
            return nums[start];
        }
        
        int mid = -1;
        int ans = 0;
        
        while(start<=end)
        {
            mid = start + (end - start)/2; 
            int next = (mid + 1)%N;
            int prev = (mid - 1 + N)%N;
            
            if(nums[mid] < nums[prev] && nums[mid] < nums[next])
            {
                ans = mid;
                break;
            }
            
            if(nums[0] <= nums[mid])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            } 
        }
        
        return nums[ans];
    }
};