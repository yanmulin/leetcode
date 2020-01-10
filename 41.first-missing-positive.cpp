class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        for (int i=0;i<sz;i++) {
            int j = nums[i];
            while (j < sz+1 && j > 0 && nums[j-1]-1 != j-1) {
                swap(nums[j-1], nums[i]);
                j = nums[i];
            }
        }
        for (int i=0;i<sz;i++) {
            if (nums[i] != i+1) return i+1;
        }
        return sz + 1;
    }
};
