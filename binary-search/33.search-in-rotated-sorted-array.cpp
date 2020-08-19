class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (target == nums[mid]) return mid;
            if (nums[high] > nums[mid]) {
                if (nums[high] >= target && target > nums[mid])
                    low = mid + 1;
                else high = mid - 1;
            } else {
                if (nums[mid] > target && target >= nums[low])
                    high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};
