#include <stack>

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        for(int i = 0;i < s.size();i++)
        {
            if (s[i] != '#')
                s1.push(s[i]);
            else
            {
                if (!s1.empty())
                    s1.pop();
            }
        }
        
        for(int i = 0;i < t.size();i++)
        {
            if (t[i] != '#')
                s2.push(t[i]);
            else
            {
                if (!s2.empty())
                    s2.pop();
            }
        }
        
        while (!s1.empty() && !s2.empty())
        {
            char temp1 = s1.top();
            char temp2 = s2.top();
            
            s1.pop();
            s2.pop();
            
            if (temp1 != temp2)
                return false;
        }
        
        if (s1.empty() == true && s2.empty() == true)
            return true;
        else
            return false;
    }
};


