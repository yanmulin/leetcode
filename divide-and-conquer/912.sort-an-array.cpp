class Solution {
private:
    int partition(vector<int> &nums, int l, int r) {
        int i = l, j = r + 1;
        while (true) {
            while (nums[++i] < nums[l])
                if (i >= r) break;
            while (nums[l] < nums[--j])
                if (j <= l) break;
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[l]);
        return j;
    }
    void quikSort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        swap(nums[l], nums[l + (r - l) / 2]);
        int m = partition(nums, l, r);
        quikSort(nums, l, m - 1);
        quikSort(nums, m + 1, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quikSort(nums, 0, nums.size()-1);
        return nums;
    }
};
