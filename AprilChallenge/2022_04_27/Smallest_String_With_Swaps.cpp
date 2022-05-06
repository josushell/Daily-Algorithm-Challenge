#include <vector>

class Solution
{
private:
    vector<int> v[100000];	// pair의 길이
    bool visited[100000];	// 방문 여부 체크
public:
    void DFS(string &s, int i, vector<char> &ch, vector<int> &indices)
    {
        ch.push_back(s[i]);
        indices.push_back(i);

        visited[i] = true;
        for(int n: v[i])
        {
            if (visited[n] == false)
                DFS(s, n, ch, indices);
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
		// Graph를 생성
        for(auto iter: pairs)
        {
            int src = iter[0];
            int dst = iter[1];

            v[src].push_back(dst);
            v[dst].push_back(src);
        }

		// 문자열의 길이만큼 돌면서 가능한 graph를 만들기
        for(int i = 0; i < s.size(); i++)
        {
            if(!visited[i])
            {
                vector<char> chars;	// 문자 저장
                vector<int> indices;	// 연결되어 갈 수 있는 인덱스 저장

                DFS(s, i, chars, indices);

                sort(chars.begin(), chars.end());
                sort(indices.begin(), indices.end());

                for(int j = 0;j < chars.size();j++)
                    s[indices[j]] = chars[j];
            }
        }

        return s;
    }

};
