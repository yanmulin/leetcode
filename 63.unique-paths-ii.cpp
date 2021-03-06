class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, 0));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (obstacleGrid[i][j]) dp[i][j] = 0;
                else if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i > 0 && j > 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else if (i > 0) dp[i][j] = dp[i-1][j];
                else if (j > 0) dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
