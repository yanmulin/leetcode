class Solution {
private:
    void getCombination(int low, int high, int k, vector<int> &solution, vector<vector<int>> &result) {
        if (k == 0) {
            result.push_back(solution);
        }
        for (int i=low;i<=high;i++) {
            solution.push_back(i);
            getCombination(i+1, high, k-1, solution, result);
            solution.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> solution;
        vector<vector<int>> result;
        getCombination(1, n, k, solution, result);
        return result;
    }
};
