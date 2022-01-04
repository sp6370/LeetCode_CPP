class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int count = 0;
        stack<char> st;
        
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(st.size()!=0 && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        
//         while(st.size()!=0)
//         {
//             char t1 = st.top();
//             st.pop();
            
//             if(st.size()==0)
//             {
//                 return -1;
//             }
            
//             char t2 = st.top();
//             st.pop();
            
//             if(t1 == t2)
//             {
//                 count++;
//             }
//             else
//             {
//                 count = count + 2;
//             }
//         }
        
        return st.size();
            
    }
};