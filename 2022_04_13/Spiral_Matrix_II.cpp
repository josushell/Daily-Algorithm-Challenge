#include <vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int row = 0;
        int col = 0;

        int rowDir = 0;
        int colDir = 1;

        for(int i = 1;i <= n * n;i++) {
            result[row][col] = i;

            int rowTemp = row + rowDir;
            int colTemp = col + colDir;

            if (rowTemp < 0 || colTemp < 0 || rowTemp == n || colTemp == n || result[rowTemp][colTemp] != 0)
            {
                // left -> right
                if (rowDir == 0 && colDir == 1) {
                    rowDir = 1;
                    colDir = 0;
                }

                // up -> down
                else if (rowDir == 1 && colDir == 0) {
                    rowDir = 0;
                    colDir = -1;
                }

                // down -> up
                else if (rowDir == -1 && colDir == 0) {
                    rowDir = 0;
                    colDir = 1;
                }

                // right -> left
                else if (rowDir == 0 && colDir == -1) {
                    rowDir = -1;
                    colDir = 0;

                }
            }
            row += rowDir;
            col += colDir;
        }

        return result;
    }
};

