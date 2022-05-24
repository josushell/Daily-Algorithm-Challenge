// Longest Valid Parentheses
// stack을 활용하여 올바른 parentheses 마다 stack에 값을 저장하고 0으로 만들어줌

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;

        int result = 0;
        int ans = 0;
        for(int i = 0;i < s.size();i++)
        {
            if (s[i] == '(')
            {
                st.push(result);
                result = 0;
            }
            else
            {
                if (!st.empty())
                {
                    result += st.top() + 2;
                    st.pop();

                    ans = max(result, ans);
                }
                else
                    result = 0;
            }
        }
        return ans;
    }
};
