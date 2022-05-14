class Solution {
public:
    void dikjstra(vector<pair<int, int>> graph[], vector<int> &dist, int start)
    {
        priority_queue<pair<int, int>> q;
        q.push({0, start});
        dist[start] = 0;
        
        while (!q.empty())
        {
            int weight = q.top().first * -1;
            int now = q.top().second;
            
            q.pop();
            
            if (dist[now] < weight)
                continue;
            
            for(int i = 0;i < graph[now].size();i++)
            {
                int temp = weight + graph[now][i].second;
                
                if (temp < dist[graph[now][i].first])
                {
                    dist[graph[now][i].first] = temp;
                    q.push({temp * -1, graph[now][i].first});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int>> graph[n + 1];
        
        for(int i = 0;i < times.size();i++)
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        
        vector<int> dist(n + 1);
        for(int i = 1;i <= n;i++)
            dist[i] = 1e9;
        
         dikjstra(graph, dist, k);
        
        int max = -1;
        for(int i = 1;i <= n;i++)
        {
            if (max < dist[i])
                max = dist[i];
        }
        
        if (max == 1e9)
            return -1;
        else
            return max;
    }
};

