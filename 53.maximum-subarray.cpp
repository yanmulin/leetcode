class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        int i, j, sum, max;
        i = j = 0;
        max = sum = nums[0];
        while (i < sz-1 && j < sz-1) {
            if (sum < 0) {
                i = j = j+1;
                sum = nums[i];
            } else {
                j ++;
                sum += nums[j];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};
