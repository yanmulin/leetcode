class Solution {
private:
    // recursion
    int coinChangeHelper(const vector<int> &coins, int end, int amount) {
        if (amount == 0) return 0;
        else if (end < 0) return -1;
        else if (coins[end] <= amount) {
            int pickLast = 1+coinChangeHelper(coins, end, amount-coins[end]);
            int notPickLast = coinChangeHelper(coins, end-1, amount);
            if (pickLast > 0 && notPickLast > 0)
                return min(pickLast, notPickLast);
            else if (pickLast > 0) return pickLast;
            else return notPickLast;
        } else return coinChangeHelper(coins, end-1, amount);
    }
    int verticalMin(const vector<vector<int>> &matrix, int col, int startRow, int endRow) {
        int min = matrix[startRow][col];
        for (int k=startRow+1;k<=endRow;k++) {
            if (min > matrix[k][col]) 
                min = matrix[k][col];
        }
        return min;
    }
public:
    // dynamic programming
    int coinChange(vector<int>& coins, int amount) {
        int sz = coins.size(), ret;
        if (sz == 0 && amount == 0) return 1;
        vector<vector<int>> dp(sz, vector<int>(amount+1, 0));
        sort(coins.begin(), coins.end());
        for (int i=0;i<sz;i++) {
            for (int j=0;j<=amount;j++) {
                if (j == 0) dp[i][j] = 0;
                else if (j < coins[i]) dp[i][j] = INT_MAX;
                else if (j % coins[i] == 0)
                    dp[i][j] = j / coins[i];
                else if (i == 0) dp[i][j] = INT_MAX;
                else {
                    int min1 = verticalMin(dp, j, 0, i-1);
                    int min2 = verticalMin(dp, j-coins[i], 0, i);
                    if (min2 == INT_MAX)
                        dp[i][j] = min1;
                    else if (min1 == INT_MAX)
                        dp[i][j] = min2+1;
                    else dp[i][j] = min(min1, min2+1);
                }
            }
        }
        ret = verticalMin(dp, amount, 0, sz-1);
        if (ret == INT_MAX) return -1;
        else return ret;
    }
};
