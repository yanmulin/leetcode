class Solution {
public:
    string getPermutation(int n, int k) {
        int total = 1;
        vector<int> nums;
        for (int i=1;i<=n;i++) {
            total *= i;
            nums.push_back(i);
        }
        int group = total, idx;
        stringstream ss;
        while (n > 0) {
            group /= n;
            idx = (k-1) / group;
            ss << nums[idx];
            nums.erase(nums.begin() + idx);
            n --;
            k -= group * idx;
        }
        return ss.str();
    }
};
