// Dijkstra

class Solution
{
private:
    // 동 서 남 북
    vector<vector<int>> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
        // 가장 가까운 노드를 저장하기 위한 {거리, {현재 x좌표, 현재 y좌표}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // 최단 거리를 저장
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX)); // 거리를 일단 무한대로 설정
        
        dist[0][0] = 0; // 시작 노드의 거리는 0으로 설정
        pq.push({0, {0,0}});    // 시작 노드를 queue에 추가
        
        while(pq.empty() == false)
        {
            auto node = pq.top();
            pq.pop();
            
            int weight = node.first;
            int dx = node.second.first;
            int dy = node.second.second;
            
            // 최대 거리 중 가장 작은 값이니까 현재보다 작은 값은 볼 필요가 없음
            if (dist[dx][dy] < weight)
                continue;
            
            if (dx == row - 1 && dy == col - 1)
                return weight;
            
            for (int i = 0;i < 4;i++)
            {
                // 상하좌우로 방향 이동 가능성 체크
                int tempRow = dx + dir[i][0];
                int tempCol = dy + dir[i][1];
                
                // 바운더리 체크
                if (tempRow < 0 || tempCol < 0 || tempRow >= row || tempCol >= col)
                    continue;
                
                int newWeight = abs(heights[dx][dy] - heights[tempRow][tempCol]);
                newWeight = max(newWeight, weight);
                
                if (dist[tempRow][tempCol] <= newWeight)
                    continue;
                
                dist[tempRow][tempCol] = newWeight;
                pq.push({newWeight, {tempRow, tempCol}});
            }
        }
        return 0;
    }
};


