#define ABS(x) ((x)>0 ? (x):-(x))
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 3) return 0;
        int i = 0, j = 1, k = size - 1;
        int closest = nums[i] + nums[j] + nums[k];
        if (closest == target) return target;
        int minDist = ABS(closest - target);
        sort(nums.begin(), nums.end());
        while (j < size - 1) {
            while (i < j && j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return target;
                int dist = ABS(sum - target);
                if (dist < minDist) {
                    closest = sum;
                    minDist = dist;
                }
                if (sum < target) while (++i > j && nums[i] == nums[i-1]);
                if (sum > target) while (--k < j && nums[k] == nums[k+1]);
            }
            j++;
            if (nums[j] != nums[j-1]) {
                i = 0;
                k = size - 1;
            } else {
                while (i < size - 1 && i < j-1 && nums[i] == nums[i+1]) i++;
                while (k > 1 && j+1 < k && nums[k] == nums[k-1]) k--;
            }
        }
        return closest;
    }
};
