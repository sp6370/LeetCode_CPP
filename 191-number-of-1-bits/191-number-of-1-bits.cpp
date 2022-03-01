class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        long mask = 1;
        for(int i=1; i<=32; i++)
        {
            if((n & mask) !=0)
            {
                count++;
            }
            //right shift on mask
            mask = (mask << 1);
        }
        return count;
    }
};