class Solution {
private:
    void getCombination(const vector<int> &nums, int start, int k, vector<int> &solution, vector<vector<int>> &result) {
        if (k == 0) {
            result.push_back(solution);
        }
        for (int i=start;i<nums.size();i++) {
            solution.push_back(nums[i]);
            getCombination(nums, i+1, k-1, solution, result);
            solution.pop_back();
        }
    }
    vector<vector<int>> combine(const vector<int> &nums, int k) {
        vector<int> solution;
        vector<vector<int>> result;
        getCombination(nums, 0, k, solution, result);
        return result;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> result;
        for (int i=0;i<=sz;i++) {
            vector<vector<int>> com = combine(nums, i);
            result.insert(result.end(), com.begin(), com.end());
        }
        return result;
    }
};
