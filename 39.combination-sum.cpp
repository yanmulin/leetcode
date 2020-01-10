class Solution {
private:
    void helper(vector<int> candidates, int target, int start, vector<int>&solution, vector<vector<int>> &results) {
        if (target < 0) return;
        if (target == 0) {
            results.push_back(solution);
        }

        int sz = candidates.size();
        for (int i=start;i<sz;i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            solution.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i, solution, results);
            solution.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> solution;
        helper(candidates, target, 0, solution, results);
        return results;
    }
};
