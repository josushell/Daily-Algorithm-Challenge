#include <vector>

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> result(row, vector<int> (col, 0));

        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                int sum = 0;
                for(int n = i - 1;n <= i + 1;n++)
                {
                    for(int m = j - 1;m <= j + 1;m++)
                    {
                        if ((n != i || m != j) && (n >= 0 && m >= 0 && n < row && m < col))
                        {
                            if (board[n][m] == 1)
                                sum++;
                        }
                    }
                }

                if (board[i][j] == 0)
                {
                    if (sum == 3)
                        result[i][j] = 1;
                    else
                        result[i][j] = 0;
                }
                else
                {
                    if (sum < 2)
                        result[i][j] = 0;
                    else if (2 <= sum && sum <= 3)
                        result[i][j] = 1;
                    else if (sum > 3)
                        result[i][j] = 0;
                }
            }
        }

        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                board[i][j] = result[i][j];
            }
        }
    }
};


