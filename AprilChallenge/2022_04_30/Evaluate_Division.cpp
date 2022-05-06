class Solution {
private:
    unordered_map<string, unordered_map<string, double>> edge;
    
public:
    double DFS(string numerator, string denominator, unordered_set<string> &visited)
    {
        if (numerator == denominator)
            return 1;
        
        visited.insert(numerator);
        
        for(auto iter : edge[numerator])
        {
            if (!visited.count(iter.first))
            {
                double res = DFS(iter.first, denominator, visited);
                if (res != -1.0)
                    return res * iter.second;
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        vector<double> result;
        unordered_set<string> visited;
        
        for(int i = 0;i < equations.size();i++)
        {
            string x = equations[i][0];
            string y = equations[i][1];
            
            edge[x][y] = values[i];
            edge[y][x] = 1 / values[i];
        }
        
        for(int i = 0;i < queries.size();i++)
        {
            if(edge.count((queries[i][0])) == 0 || edge.count(queries[i][1]) == 0)
            {
                result.push_back(-1);
                continue;
            }
            else
            {
                double temp = DFS(queries[i][0], queries[i][1], visited);
                result.push_back(temp);
                visited.clear();
            }
        }
        return result;
    }
};


