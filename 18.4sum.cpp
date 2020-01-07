class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i=0;i<size-2;i++) {
            for (int j=size-1;j>i;j--) {
                int twoSum = nums[i] + nums[j];
                int m = i + 1, n = j - 1;
                while (m < n) {
                    int sum = twoSum + nums[m] + nums[n];
                    if (sum == target) res.push_back({nums[i], nums[m], nums[n], nums[j]});
                    if (sum <= target) while (++m < n && nums[m-1] == nums[m]);
                    if (sum >= target) while (m < --n && nums[n+1] == nums[n]);
                }
                while (j > i && nums[j] == nums[j-1]) j--;
            }
            while (i < size-2 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};
