class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val = 1;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i=0;i<=n/2;i++) {
            int low = i, high = n - i - 1;
            for (int j=low;j<=high;j++) m[low][j] = val++;
            for (int j=low+1;j<high;j++) m[j][high] = val++;
            for (int j=high;low!=high&&j>=low;j--) m[high][j] = val++;
            for (int j=high-1;j>low;j--) m[j][low] = val++;
        }
        return m;
    }
};
