// Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1) return 0;
        int cover = nums[0], steps = 0;
        for (int i=0;i<sz;) {
            cover = nums[i] + i;
            if (cover >= sz - 1) return steps + 1;
            int max = 0, next;
            for (int j=i+1;j<=cover;j++) {
                if (nums[j] + j > max) {
                    max = nums[j] + j;
                    next = j;
                }
            }
            i = next;
            steps ++;
        }
        return steps;
    }
};
