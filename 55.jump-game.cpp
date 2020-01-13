class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) return true;
        int cover = nums[0];
        for (int i=0;cover<sz-1;) {
            int newCover = 0;
            while (++i <= cover) {
                if (nums[i] + i > newCover) 
                    newCover = nums[i] + i;
            }
            if (newCover <= cover) return false;
            i = cover;
            cover = newCover;
        }
        return true;
    }
};
