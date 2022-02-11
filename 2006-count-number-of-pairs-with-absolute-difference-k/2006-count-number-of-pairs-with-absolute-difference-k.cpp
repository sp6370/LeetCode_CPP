class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            int key1 = nums[i] - k;
            int key2 = nums[i] + k;
            
            ans = ans + mp[key1] + mp[key2];     
            ++mp[nums[i]];
        }
        return ans;
    }
};

// | x - y | = k
// => x - y = k
// => x - y = -k