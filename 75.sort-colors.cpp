class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) return;
        int i = 0 , j, k = sz - 1;
        while (nums[i] == 0 && i < sz-1) i++;
        while (nums[k] == 2 && k > 0) k--;
        j = i;
        while (j <= k) {
            if (nums[j] == 2) {
                swap(nums[k--], nums[j]);
            } else if (nums[j] == 1) {
                j ++;
            } else if (nums[j] == 0) {
                swap(nums[i++], nums[j++]);
            } else assert(false);
        }
    }
};
