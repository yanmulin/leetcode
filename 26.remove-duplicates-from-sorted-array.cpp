class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return size;
        int i, j;
        for (i=j=0;j<size;i++) {
            nums[i] = nums[j++];
            while (j < size && nums[j] == nums[j-1]) j++;
        }
        while (i++ < j) nums.pop_back();
        return nums.size();
    }
};
