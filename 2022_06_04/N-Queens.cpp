class Solution {
private:
    int N;
    vector<vector<string>> result;
    int ans = 0;
    int graph[10];
public:
    bool isPossible(int n, int i)
    {
        for(int idx = 0;idx < n;idx++)
        {
            if (graph[idx] == i || abs(idx - n) == abs(graph[idx] - i))
                return false;
        }
        return true;
        
    }
    void queens(int n, vector<string> &temp)
    {
        if (N == n)
        {
            result.push_back(temp);
            ans++;
            return;
        }
        
        for(int i = 0;i < N;i++)
        {
            graph[n] = i;
            string str;
            if (isPossible(n, i))
            {
                for(int idx = 0;idx < N;idx++)
                {
                    if (idx == i)
                        str.push_back('Q');
                    else
                        str.push_back('.');
                }
                temp.push_back(str);
                queens(n + 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> str;
        queens(0, str);
        
        return result;
    }
};


