class Solution {
public:
    
    int getBits(int num)
    {
        int count = 0;
        
        while(num)
        {
            num = num & (num - 1);
            count++;
        }
        
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0; i<=n; i++)
        {
            if(i == 0)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(getBits(i));
            }
        }
        return result;
    }
};