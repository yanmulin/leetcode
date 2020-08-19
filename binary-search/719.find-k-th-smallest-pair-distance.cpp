class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        vector<int> dp(high+1, 0);
        for (int i=0;i<high+1;i++) {}
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0, j = 0;
            for (int i=0;i<n-1;i++) {
                while (j < n && nums[j] - nums[i] <= mid) j ++;
                count += j - i - 1;
            }
            if (count >= k) high = mid - 1;
            else if (count < k) low = mid + 1;
        }
        return low;
    }
};
