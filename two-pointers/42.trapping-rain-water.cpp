class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int l = 0, r = n - 1, l_max = height[l], r_max = height[r];
        int ans = 0;
        while (l < r) {
            if (l_max <= r_max) {
                ans += l_max - height[l++];
                l_max = max(height[l], l_max);
            } else {
                ans += r_max - height[r--];
                r_max = max(height[r], r_max);
            }
        }
        return ans;
    }
};
