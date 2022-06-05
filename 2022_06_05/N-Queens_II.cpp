// backtracking

class Solution {
private:
    int N;
    int result = 0;
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
    void queens(int n)
    {
        if (N == n)
        {
            result++;
            return;
        }
        
        for(int i = 0;i < N;i++)
        {
            graph[n] = i;
            if (isPossible(n, i))
                queens(n + 1);
        }
    }
    int totalNQueens(int n) {
        N = n;
        queens(0);
        
        return result;
    }
};
