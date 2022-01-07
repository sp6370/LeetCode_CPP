class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> mp;
        vector<int> ans;
        
        for(int i = 0; i<nums.size(); i++)
        {
            int cValue = nums[i];
            int key = target - cValue;
            
            if(mp.find(key) != mp.end())
            {
                ans.push_back(mp[key]);
                ans.push_back(i);
                break;
            }
            else
            {
                mp[cValue] = i;
            }
        }
        
        return ans;
        
    }
};