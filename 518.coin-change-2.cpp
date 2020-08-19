class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sz = coins.size(), ret = 0;
        if (sz == 0) return 1;
        vector<vector<int>> dp(sz, vector<int>(amount+1, 0));
        for (int i=0;i<sz;i++) {
            for (int j=0;j<=amount;j++) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                if (j - coins[i] >= 0) 
                    dp[i][j] += dp[i][j-coins[i]];
                if (i > 0)
                    dp[i][j] += dp[i-1][j];
            }
        }
        return dp[sz-1][amount];
    }
};
