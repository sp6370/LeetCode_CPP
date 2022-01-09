class Solution {
public:
    
    int bSearch(vector<int> nums, int target, int start, int end)
    {
        if(start>end)
        {
            return -1;
        }
        
        int mid = (start+end)/2;
        
        if(nums[mid] == target)
        {
            return mid;
        }
        
        if(nums[mid] > target)
        {
            return bSearch(nums, target, start, mid-1);
        }
        else
        {
            return bSearch(nums, target, mid+1, end);
        }
    }
    
    
    int search(vector<int>& nums, int target) {
        return bSearch(nums, target, 0, nums.size()-1);
    }
};