class Solution {
private:
    bool searchMatrixHelper(
        const vector<vector<int>>& m,
        int rstart, int rend, 
        int cstart, int cend, 
        int target
    ) {
        if (rstart > rend) return false;
        if (cstart > cend) return false;
        int right_uppermost = m[rstart][cend];
        if (target == right_uppermost) return true;
        else if (target > right_uppermost)
            return searchMatrixHelper(m, rstart+1, rend, cstart, cend, target);
        else return searchMatrixHelper(m, rstart, rstart, cstart, cend-1, target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int r = matrix.size(), c = matrix[0].size();
        return searchMatrixHelper(matrix, 0, r-1, 0, c-1, target);
    }
};
