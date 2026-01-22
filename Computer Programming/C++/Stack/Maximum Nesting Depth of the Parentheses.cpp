class Solution {
public:
    int maxDepth(string s) 
    {
        int maximum = 0;
        int current = 0;

        stack<char>st;

        for(int i = 0;i<s.size();i++)
        {
            current = st.size();
            maximum = max(maximum,current);

            if(s[i] == '(')
            {
                st.push('(');
            }
            if(s[i] == ')')
            {
                st.pop();
            }
        }    

        return maximum;
    }
};
