#include <queue>
#include <vector>
#include <cstdlib>

class Solution
{
public:
    int getDistance(vector<int> v1, vector<int> v2)
    {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int len = points.size();
        int sum = 0;
        int curNode, curDist;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(len);

        pq.push({0, 0});
        while (!pq.empty())
        {
            curNode = pq.top().second;
            curDist = pq.top().first;
            pq.pop();

            if (visited[curNode] == true)
                continue;
            else
            {
                visited[curNode] = true;
                sum += curDist;
            }
            for(int i = 0;i < len;i++)
                if (visited[i] == false)
                    pq.push({getDistance(points[curNode], points[i]), i});
        }

        return sum;
    }

};
