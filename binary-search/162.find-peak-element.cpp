class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        size_t n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == n - 1) break;
            if (nums[mid] > nums[mid+1])
                high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
