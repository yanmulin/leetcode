#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;
        int i = size - 1;
        while (true) {
            i --;
            if (nums[i] < nums[i+1]) {
                int j = size;
                while (nums[--j] <= nums[i]);
                swap(nums, i, j);
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }
            if (i == 0) {
                reverse(nums.begin(), nums.end());
                break;
            }
        }
        return;
    }
};
