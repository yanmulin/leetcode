class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        int i = 0, j = 0;
        while (j < sz) {
            nums[i++] = nums[j++];
            if (j < sz && nums[j] == nums[j-1])
                nums[i++] = nums[j++];
            while(j < sz && nums[j] == nums[j-1]) j++;
        }
        return i;
    }
};