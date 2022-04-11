#include <vector>

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int col = grid[0].size();
        int row = grid.size();
        
        vector<vector<int>> result(row, vector<int>(col, 0));
        
        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                int colIdx = (j + k) % col;
                int rowIdx = (i + (j + k) / col) % row;
                result[rowIdx][colIdx] = grid[i][j];
            }
        }
        return result;
    }
};
