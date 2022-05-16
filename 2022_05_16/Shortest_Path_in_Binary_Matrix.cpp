class Solution {
private:
    // direction
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int n, m;
public:
    void BFS(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j)
    {
        queue<pair<int, int>> q;
        
        if (grid[i][j] == 1)
            return;
        
        q.push({i, j});
        visited[i][j] = true;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            for(int dir = 0;dir < 8;dir++)
            {
                int tempX = x + dx[dir];
                int tempY = y + dy[dir];
                
                if (tempX < 0 || tempY < 0 || tempX >= n || tempY >= m)
                    continue;
                
                if (grid[tempX][tempY] == 0)
                {
                    visited[tempX][tempY] = true;
                    grid[tempX][tempY] = grid[x][y] + 1;
                    q.push({tempX, tempY});
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = (int)grid.size();
        m = (int)grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        BFS(grid, visited, 0, 0);
        
        if (visited[n - 1][m - 1] == false)
            return -1;
        else
            return grid[n - 1][m - 1] + 1;
    }
};
