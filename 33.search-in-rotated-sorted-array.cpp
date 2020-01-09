class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return -1;
        if (size == 1) return nums[0] == target ? 0 : -1;
        int mid, low = 0, high = size - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (low == high) return -1;
            if (nums[low] < nums[high] && (target < nums[low] || target > nums[high])) // not found
                return -1;

            if (nums[high] > nums[mid] && target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
                continue;
            }

            if (nums[low] < nums[mid] && target < nums[mid] && target >= nums[low]) {
                high = mid - 1;
                continue;
            }

            if (nums[mid] < nums[low]) {
                high = mid - 1;
                continue;
            }

            if (nums[mid] > nums[high]) {
                low = mid + 1;
                continue;
            }
        }
        return -1;
    }
};
