// idea: DFS + DP
// 가능한 경로의 최대를 찾는 것이므로 DFS를 사용해서 쉽게 풀 수 있다.
// 이때 시간 초과의 가능성이 있기 때문에 DP를 사용하여 경로를 저장해서 이전에 계산한 경로는 다시 계산하지 않는다.

class Solution {
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
public:
    int DFS(vector<vector<int>>& matrix, vector<vector<int>> &dp, int x, int y)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        
        int temp = 0;
        bool flag = false;

		// DFS 적용
        for(int dir = 0;dir < 4;dir++) {
            int tempX = x + dx[dir];
            int tempY = y + dy[dir];
            
            if (tempX < 0 || tempY < 0 || tempX >= matrix.size() || tempY >= matrix[0].size())
                continue;
            
            if (matrix[tempX][tempY] > matrix[x][y]) {
                flag = true;

				// DFS의 결과 중 큰 값을 저장
                int cur = DFS(matrix, dp, tempX, tempY);
                temp = max(cur, temp);
            }
        }
        
		// DP 적용
        if (flag == false)
            return 0;
        else
            return dp[x][y] = temp + 1;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int maxV = 1;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                int result = DFS(matrix, dp, i, j);
                
                maxV = max(maxV, result + 1);
            }
        }
        return maxV;
    }
};
