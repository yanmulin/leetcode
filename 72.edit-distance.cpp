class Solution {
private:
    int minDist(int a, int b, int c) {
        return min(a, min(b, c));
    }
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        if (sz1 == 0) return sz2;
        if (sz2 == 0) return sz1;
        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1));
        dp[0][0] = 0;
        for (int i=1;i<=sz1;i++) dp[i][0] = i;
        for (int i=1;i<=sz2;i++) dp[0][i] = i;
        for (int i=1;i<=sz1;i++) {
            for (int j=1;j<=sz2;j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = minDist(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[sz1][sz2];
    }
};
