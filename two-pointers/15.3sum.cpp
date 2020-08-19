class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0;i < n - 2;i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (l > i + 1 && nums[l] == nums[l - 1]) {
                    l ++;
                    continue;
                } else if (r < n - 1 && nums[r] == nums[r + 1]) {
                    r --;
                    continue;
                }
                int sum = nums[l] + nums[r];
                if (sum == -nums[i]) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    r --;
                    l ++;
                } else if (sum > -nums[i]) r --;
                else l ++;
            }
        }
        return ans;
    }
};
