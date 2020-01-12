class Solution {
private:
    bool next(vector<int> &nums) {
        int sz = nums.size();
        int i = sz - 2, j = sz - 1;
        while (i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i < 0) return false;
        while (j > i && nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next(nums));
        return res;
    }
};
