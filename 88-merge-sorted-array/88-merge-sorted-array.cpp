class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> result(m+n);
        int c1 = 0;
        int c2 = 0;
        for(int i=0; i<m+n; i++)
        {
            if(c1>=m)
            {
                result[i] = nums2[c2++];
                continue;
            }
            if(c2>=n)
            {
                result[i] = nums1[c1++];
                continue;
            }
            
            int tmp = -1;
            
            if(nums1[c1] < nums2[c2])
            {
                tmp = nums1[c1];
                c1++;
            }
            else
            {
                tmp = nums2[c2];
                c2++;
            }
            
            result[i] = tmp;
        }
        nums1 = result;
    }
};