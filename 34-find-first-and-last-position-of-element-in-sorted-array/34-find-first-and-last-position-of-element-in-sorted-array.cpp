class Solution {
public:
    int bFSearch(vector<int> nums, int target, int start, int end)
    {
        if(start>end)
        {
            return -1;
        }
        
        int mid = start + (end - start)/2;
        
        if(nums[mid] == target)
        {
            int ls = bFSearch(nums, target, start, mid-1);
            if(ls!=-1)
            {
                return ls;
            }
            else
            {
                return mid;
            }
        }
        
        if(nums[mid] > target)
        {
            return bFSearch(nums, target, start, mid-1);
        }
        else
        {
            return bFSearch(nums, target, mid+1, end);
        }
    }
    
    int bLSearch(vector<int> nums, int target, int start, int end)
    {
        if(start>end)
        {
            return -1;
        }
        
        int mid = start + (end - start)/2;
        
        if(nums[mid] == target)
        {
            int ls = bLSearch(nums, target, mid+1, end);
            if(ls!=-1)
            {
                return ls;
            }
            else
            {
                return mid;
            }
        }
        
        if(nums[mid] > target)
        {
            return bLSearch(nums,target, start, mid-1);
        }
        else
        {
            return bLSearch(nums,target, mid+1, end);
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lo = bFSearch(nums, target, 0, nums.size()-1);
        
        int ro = bLSearch(nums, target, 0, nums.size()-1);
        
        vector<int> ans;
        ans.push_back(lo);
        ans.push_back(ro);
    
        return ans;
    }
};