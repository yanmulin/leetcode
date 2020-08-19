class Solution {
private:
    int majorityElement(vector<int>& nums, int l, int r) {
        if (r - l <= 1) return nums[l];
        int m = l + (r - l) / 2;
        int ml = majorityElement(nums, l,  m);
        int mr = majorityElement(nums, m, r);
        if (ml == mr) return ml;
        else return count(nums.begin()+l, nums.begin()+r, ml)
                  > count(nums.begin()+l, nums.begin()+r, mr) ?
                  ml : mr;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size());
    }
};
