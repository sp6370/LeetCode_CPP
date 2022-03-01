class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result(n);
        int offsetValue = 1;
        
        result.push_back(0);
        
        for(int i=1; i<=n; i++)
        {
            if(offsetValue * 2 == i)
            {
                offsetValue = i;
            }
            
            result[i] = 1 + result[i - offsetValue];
        }
        
        return result;
    }
};