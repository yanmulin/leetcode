class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        size_t an = A.size(), bn = B.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < an && j < bn) {
            if (A[i][0] > B[j][1]) j ++;
            else if (A[i][1] < B[j][0]) i ++;
            else {
                ans.emplace_back(max(A[i][0], B[j][0]), min(A[i][1], B[j][1]));
                if (A[i][1] >= B[j][1])
                    j ++;
                else i ++;
            }
        }
        return ans;
    }
};
