class Solution {
public:
    
    int robSolver(vector<int> nums, int n, vector<int> &data)
    {
        if(n == 0)
        {
            return 0;
        }
        
        if(n == 1)
        {
            return nums[0];
        }
        
        if(data[n-1] != -1)
        {
            return data[n-1];
        }
        
        int profit1 = nums[n-1] + robSolver(nums, n-2, data);
        int profit2 = robSolver(nums, n-1, data);
        
        data[n-1] = max(profit1, profit2);
        return data[n-1];
    }
    
    int rob(vector<int>& nums) {
        vector<int> data(nums.size(), -1);
        return robSolver(nums, nums.size(), data);
    }
};