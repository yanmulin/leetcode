class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        int i, sum, max;
        i = 1;
        max = sum = nums[0];
        while (i < sz) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            if (sum > max) {
                max = sum;
            }
            i ++;
        }
        return max;
    }
};
