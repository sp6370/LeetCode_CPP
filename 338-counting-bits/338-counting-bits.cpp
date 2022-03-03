class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> DP(n);
        int offset = 1;
        DP.push_back(0);
        // 0: 0 0 0
        // 1: 0 0 1
        // 2: 0 1 0
        // 3: 0 1 1
        // 4: 1 0 0
        // 5: 1 0 1
        // 6: 1 1 0
        // 7: 1 1 1
        
        for(int i=1; i<=n; i++)
        {
            if(offset * 2 == i)
            {
                offset = i;
            }
            
            DP[i] = 1 + DP[i - offset];
        }
        
        return DP;
    }
};