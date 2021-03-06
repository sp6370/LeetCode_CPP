class Solution {
public:
    int countBinarySubstrings(string s) {
        
        // let's first build vector storing frequenecy of consecutive occurences
        vector<int> freq;
        int j;
        int count;
        char key;
        
        for(int i=0; i<s.size(); i++)
        {
            key = s[i];
            j = i+1;
            count = 1;
            
            while((j)<s.size() && s[j] == key)
            {
                ++j;
                ++count;    
            }
            freq.push_back(count);
            i=j-1;
            // why?
            // j => Is now pointing to the correct element; once the control goes back to loop start i is incremented again
        }
        
        int ans = 0;
        for(int i=0; i<freq.size()-1; i++)
        {
            ans = ans + min(freq[i], freq[i+1]);
        }
        
        return ans;
    }
};