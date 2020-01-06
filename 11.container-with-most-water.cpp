#define ABS(x) ((x)>0?(x):-(x))
#define MIN(a, b) ((a)>(b)?(b):(a))
#define MAX(a, b) ((a)>(b)?(a):(b))
class Solution {
private:
    int computeArea(vector<int>& height, int i, int j) {
        return MIN(height[i], height[j]) * ABS(i - j);
    }
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max = computeArea(height, i, j);
        while (i < j) {
            if (height[i] < height[j]) {
                i ++;
            } else {
                j --;
            }
            int area = computeArea(height, i, j);
            max = MAX(area, max);
        }
        return max;
    }
};
