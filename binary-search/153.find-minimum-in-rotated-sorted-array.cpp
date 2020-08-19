class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > 0 && nums[mid] < nums[mid-1])
                return nums[mid];
            else if (nums[high] >= nums[mid]) 
                high = mid - 1;
            else low = mid + 1; 
        }
        assert(low == 0);
        return nums[low]; // low == 0
    }
};
