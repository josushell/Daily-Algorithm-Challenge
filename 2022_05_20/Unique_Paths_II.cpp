// DFS + DP
// DFS로 경로를 찾을 수 있지만, 시간초과의 가능성이 크기 때문에 dp로 경로를 저장해서 연산 횟수를 줄인다.
// 이때 (m - 1, n - 1) 좌표까지의 경로는 (m - 2, n - 1) + (m - 1, n - 2) 까지의 경로를 더한 것이므로 DFS를 돌때 m-1, n-1부터 탐색하여 dp 테이블에 저장하는 메모이제이션을 사용할 수 있다.

class Solution {
private:
    int dx[2] = {0, -1};
    int dy[2] = {-1, 0};
    int m, n;
public:
    
    int DFS(vector<vector<int>>& graph, vector<vector<int>> &dp, int x, int y)
    {
        if (graph[x][y] == 1)
            return dp[x][y] = 0;
        
        if (dp[x][y] != -1)
            return dp[x][y];

        int ans = 0;
        for(int dir = 0;dir < 2;dir++)
        {
            int tempX = x + dx[dir];
            int tempY = y + dy[dir];
            
            if (tempX < 0 || tempY < 0 || tempX >= m || tempY >= n)
                continue;
            
            else if (graph[tempX][tempY] != 1)
            {
                int res = DFS(graph, dp, tempX, tempY);
                ans += res;
            }
        }
        return dp[x][y] = ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = (int)obstacleGrid.size();
        n = (int)obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        dp[0][0] = 0;
        DFS(obstacleGrid, dp, m - 1, n - 1);
        
        return dp[m - 1][n - 1];;
    }
};

