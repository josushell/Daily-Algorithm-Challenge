// DP: 메모이제이션 활용하여 이전에 저장한 값을 활용

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 1e9));
        dp[0][0] = triangle[0][0];
        for(int i = 1;i < triangle.size();i++)
        {
            for(int j = 0;j <= i;j++)
            {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }  
        
        int total = 1e9;
        for(int i = 0;i < triangle.size();i++)
        {
            total = min(total, dp[triangle.size() - 1][i]);
        }
        
        return total;
    }
};


