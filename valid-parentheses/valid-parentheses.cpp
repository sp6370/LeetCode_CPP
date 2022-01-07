class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
        
        for(int i = 0; i<s.size(); i++)
        {
            char tmp = s[i];
            
            if(tmp == '}' || tmp == ')' || tmp == ']')
            {   
                if(st.empty())
                {
                    return false;
                }
                
                char stTop = st.top();
                if(stTop == mp[tmp])
                {
                    st.pop();
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                st.push(tmp);
            }
        }
        
        return st.empty();
    }
};