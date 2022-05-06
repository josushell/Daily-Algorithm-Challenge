class Solution {
public:
    void BFS(vector<int> &color, vector<vector<int>> graph, int root, int c, bool &result)
    {
        queue<int> q;
        q.push(root);
        color[root] = c;
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for(int i = 0;i < graph[temp].size();i++)
            {
                if (color[graph[temp][i]] == 0)
                {
                    color[graph[temp][i]] = color[temp] * -1;
                    q.push(graph[temp][i]);
                }
                else if (color[temp] + color[graph[temp][i]] != 0)
                {
                    result = false;
                    return;
                }
            }
            
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        bool result = true;
        
        int V = graph.size();   // number of node
        int E = 0;              // number of edge
        vector<int> color(V, 0);
        
        for(int i = 0;i < V;i++)
        {
            for(int j = 0;j < graph[i].size();j++)
                E++;
        }
        E /= 2;
        
        for(int i = 0;i < V;i++)
        {
            if (result == false)
                break;
            else if (color[i] == 0)
                BFS(color, graph, i, 1, result);
        }
        
        return result;
    }
};


