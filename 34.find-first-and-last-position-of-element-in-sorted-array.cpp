#include <vector>
using namespace std;

class Solution {
private:
    int bsearch(vector<int> &nums, int low, int high, int target) {
        while (low <= high) {
            if (target < nums[low] || nums[high] < target) return -1;
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int pos = bsearch(nums, 0, n-1, target);
        int high = -1, low = -1;
        if (pos >= 0) {
            int h, l;
            h = l = pos;
            do {
                high = h ++;
                h = bsearch(nums, h, n-1, target);
            } while (h >= 0);
            do {
                low = l --;
                l = bsearch(nums, 0, l, target);
            } while (l >= 0);
        }
        return {low, high};
    }
};
