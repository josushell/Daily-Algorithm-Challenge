// DP: table에 더해서 저장한 다음 return은 값을 뺀 것으로 반환
// cf: boj에 같은 문제 있음 11660(silver 1)

class NumMatrix {
private:
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {

        for(int i = 1;i < matrix.size();i++)
            matrix[i][0] += matrix[i - 1][0];

        for(int i = 1;i < matrix[0].size();i++)
            matrix[0][i] += matrix[0][i - 1];

        for(int i = 1;i < matrix.size();i++)
        {
            for(int j = 1; j < matrix[0].size();j++)
            {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + matrix[i][j];
            }
        }

        for(int i = 0;i < matrix.size();i++)
            v.push_back(matrix[i]);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
            return v[row2][col2];

        if (row1 == 0)
            return v[row2][col2] - v[row2][col1 - 1];

        if (col1 == 0)
            return v[row2][col2] - v[row1 - 1][col2];

        return v[row2][col2] - v[row2][col1 - 1] - v[row1 - 1][col2] + v[row1 - 1][col1 - 1];
    }
};






/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
