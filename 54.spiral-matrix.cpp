class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nr = matrix.size();
        if (nr == 0) return {};
        int nc = matrix[0].size();
        vector<int> res;
        int m = (min(nr, nc)+1) / 2;
        for (int i=0;i<m;i++) {
            int low = i, rhigh = nr - i - 1, chigh = nc - i - 1;
            for (int j=low;j<=chigh;j++) res.push_back(matrix[low][j]);
            for (int j=low+1;j<=rhigh;j++) res.push_back(matrix[j][chigh]);
            for (int j=chigh-1;rhigh>low&&j>low;j--) res.push_back(matrix[rhigh][j]);
            for (int j=rhigh;chigh>low&&j>low;j--) res.push_back(matrix[j][low]);
        }
        return res;
    }
};
