class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size(), jps[sz]; // jps[i] stands for longest distant jumped in i steps
        if (sz == 0) return -1;
        if (sz == 1) return 0;
        if (sz == 2 || nums[0] >= sz - 1) return 1;
        jps[0] = 0; jps[1] = nums[0];
        for (int i=2;i<sz;i++) {
            int max = 0;
            for (int j=jps[i-2]+1;j<=jps[i-1];j++) {
                if (nums[j] + j >= sz - 1) return i;
                if (nums[j] + j > max) max = nums[j] + j;
            }
            jps[i] = max;
        }
        return sz-1;
    }
};
