class Solution {
public:
    int firstUniqChar(string s) {
        
        //let's build a hashmap
        unordered_map<char, int> mp;
        int result = -1;
        
        for(int i=0; i<s.size(); i++)
        {
            ++mp[s[i]];
        }
        
        //then go through string to do lookup
        for(int i=0; i<s.size(); i++)
        {
            if(mp[s[i]] == 1)
               {
                   result = i;
                   break;
               }
        }
        
        // return the answer
        
        return result;
        }
};