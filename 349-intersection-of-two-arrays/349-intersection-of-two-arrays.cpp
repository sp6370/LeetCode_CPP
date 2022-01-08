class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i=0;
        int j=0;
        
        vector<int>ans;
        map<int, bool> mp;
        
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                // if value already exists in the answer don't push
                if(mp.find(nums1[i])==mp.end())
                {
                    ans.push_back(nums1[i]);
                    mp[nums1[i]] = true;
                    i++;
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            else
            {
                if(nums1[i] < nums2[j])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }
        
        return ans;
    }
};