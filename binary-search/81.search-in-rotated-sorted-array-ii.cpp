class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == nums[mid]) return true;
            if (nums[high] > nums[mid]) {
                if (nums[high] >= target && target > nums[mid]) low = mid + 1;
                else high = mid - 1;
            } else if (nums[mid] > nums[high]) {
                if (nums[low] <= target && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            } else high --; // nums[mid] == nums[high]
        }
        return false;
    }
};
