class Solution {
private:
    int firstGreaterOrEqualTo(const vector<int>& nums, int start, int end, int target) {
        int low = start, high = end;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstGreaterOrEqualTo(nums, 0, n - 1, target);
        if (first < n && nums[first] == target)
            return {first, firstGreaterOrEqualTo(nums, first + 1, n - 1, target+1)-1};
        else return {-1, -1};
    }
};
