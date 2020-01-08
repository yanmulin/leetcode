class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if (size == 0) return size;
        int i, j;
        i = j = 0;
        while (true) {
            while (j < size && nums[j] == val) j++;
            if (j == size) break;
            nums[i++] = nums[j++];
        }
        while (i++ < j) nums.pop_back();
        return nums.size();
    }
};
