class Solution {
public:
    int t[201][10001];
    Solution()
    {
        memset(t, -1, sizeof(t));
    }
    
    int subsetSum(vector<int> arr, int N, int k)
    {
        if(N==0 && k==0)
        {
            return 1;
        }
        
        if(k==0)
        {
            return 1;
        }
        
        if(k!=0 && N==0)
        {
            return 0;
        }
        
        if(t[N][k]!=-1)
        {
            return t[N][k];
        }
        
        if(arr[N-1]<=k)
        {
            t[N][k] = subsetSum(arr, N-1, k-arr[N-1]) || subsetSum(arr, N-1, k);
        }
        else
        {
            t[N][k] = subsetSum(arr, N-1, k);
        }
        
        return t[N][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        
        if(sum%2!=0)
        {
            return 0;
        }
        
        return subsetSum(nums, nums.size(), sum/2);
    }
};