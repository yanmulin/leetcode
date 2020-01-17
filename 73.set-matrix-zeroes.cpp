class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int sz1 = matrix.size();
        if (sz1 == 0) return;
        int sz2 = matrix[0].size();
        bool rows[sz1], cols[sz2];
        memset(rows, 0, sz1 * sizeof(bool));
        memset(cols, 0, sz2 * sizeof(bool));
        for (int i=0;i<sz1;i++) {
            for (int j=0;j<sz2;j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i=0;i<sz1;i++) {
            for (int j=0;j<sz2;j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};
