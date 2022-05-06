class Solution {
public:
    string removeDuplicates(string s, int k) {
        // {문자, 문자가 몇개나 있는지}
        stack<pair<char, int>> st;
        
        for(int i = 0;i < s.size();i++)
        {
            // 같은 문자가 아니면 넣기
            if (st.empty() || st.top().first != s[i])
                st.push({s[i], 1});
            
            // 이전이랑 같은 문자면 빼고 갯수를 증가시켜서 넣음
            else
            {
                auto temp = st.top();
                st.pop();
                st.push({s[i], temp.second + 1});
            }
            
            // 근데 연속된 갯수가 K개면 제거함
            if (st.top().second == k)
                st.pop();
        }
       
	   // stack에 있는 문자들을 넣고 마지막에 뒤집기	
        string result = "";
        while (!st.empty())
        {
            for(int i = 0;i < st.top().second;i++)
            {
                result += st.top().first;
            }
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};


