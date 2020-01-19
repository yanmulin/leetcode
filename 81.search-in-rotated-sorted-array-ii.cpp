class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return false;
        if (size == 1) return nums[0] == target ? true : false;
        int mid, low = 0, high = size - 1;
        while (low <= high) {
            if (nums[low] < nums[high] && (target < nums[low] || target > nums[high])) // not found
                return false;
            while (low < high && nums[low]==nums[high]){
                low++;
            }
            mid = (low + high) / 2;
            if (nums[mid] == target) return true;
            if (low == high) return false;

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
            low++;
        }
        return false;
    }
};
