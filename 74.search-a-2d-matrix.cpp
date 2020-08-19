class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sz1 = matrix.size();
        if (sz1 == 0) return false;
        int sz2 = matrix[0].size();
        int low = 0, high = sz1 * sz2 - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int r = mid / sz2;
            int c = mid % sz2;
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
