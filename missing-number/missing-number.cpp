class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int maxValue = -1;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum = sum+nums[i];
        }
        int n = nums.size();
        int TS = (n * (n+1))/2;
        
        return TS - sum;
    }
};