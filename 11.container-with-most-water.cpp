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
        int size = height.size();
        if (size < 2) return 0;
        int max = computeArea(height, 0, 1);
        int i = 0, j = 1;
        for (int k=2;k<size;k++) {
            for (int n=0;n<=k;n++) {
                int area = computeArea(height, n, k);
                if (area >= max) {
                    i = n; j = k;
                    max = area;
                }
            }
        }
        return max;
    }
};
