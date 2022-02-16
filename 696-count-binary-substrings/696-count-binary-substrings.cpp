class Solution {
public:
    int countBinarySubstrings(string s) {
        
        // let's first build vector storing frequenecy of consecutive occurences
        vector<int> freq;
        int j;
        int count;
        
        for(int i=0; i<s.size(); i++)
        {
            char key = s[i];
            j = i+1;
            count = 1;
            while((j)<s.size() && s[j] == key)
            {
                ++j;
                ++count;    
            }
            freq.push_back(count);
            i=j-1;
        }
        
        int ans = 0;
        for(int i=0; i<freq.size()-1; i++)
        {
            ans = ans + min(freq[i], freq[i+1]);
        }
        
        return ans;
    }
};