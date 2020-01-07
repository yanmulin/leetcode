class Solution {
private:

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0) return {};
        int j=0, k=size-1;
        for (int i=1;i<size-1;) {
            while (j < i && i < k) {
                int sum = nums[j] + nums[i] + nums[k];
                if (sum == 0) res.push_back({nums[j], nums[i], nums[k]});
                if (sum <= 0) while (++j < i && nums[j] == nums[j-1]);
                if (sum >= 0) while (--k > i && nums[k] == nums[k+1]);
            }
            i++;
            if (nums[i] != nums[i-1]) {
                j = 0;
                k = size - 1;
            } else {
                while (j > 0 && j < i && nums[j] == nums[j-1]) j++;
                while (k < size - 1 && k > i && nums[k] == nums[k+1]) k--;
            }
        }
        return res;
    }
};
