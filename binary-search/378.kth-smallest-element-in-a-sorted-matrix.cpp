class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        size_t n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int total = 0, s = n;
            for (auto &row: matrix) {
                s = distance(row.begin(), upper_bound(row.begin(), row.end(), mid));
                total += s;
            }
            if (total >= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
