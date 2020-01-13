
class Solution {
private:
    bool *colMasks;
    bool *diagonMasks;
    bool *rdiagonMasks;
    bool isValid(int n, int r, int c) {
        if (colMasks[c]) return false;
        if (diagonMasks[n-r+c-1]) return false;
        if (rdiagonMasks[r + c]) return false;
        return true;
    }
    void recurse(int n, int row, int &count) {
        if (row == n) {
            count ++;
            return;
        }
        for (int c=0;c<n;c++) {
            if (!isValid(n, row, c)) continue;
            colMasks[c] = true;
            diagonMasks[n-row+c-1] = true;
            rdiagonMasks[row+c] = true;
            recurse(n, row+1, count);
            colMasks[c] = false;
            diagonMasks[n-row+c-1] = false;
            rdiagonMasks[row+c] = false;
        }
    }
public:
    int totalNQueens(int n) {
        colMasks = new bool[n];
        diagonMasks = new bool[2*n-1];
        rdiagonMasks = new bool[2*n-1];
        memset(colMasks, 0, n * sizeof(bool));
        memset(diagonMasks, 0, (2*n-1) * sizeof(bool));
        memset(rdiagonMasks, 0, (2*n-1) * sizeof(bool));
        int count = 0;
        recurse(n, 0, count);
        delete [] colMasks;
        delete [] diagonMasks;
        delete [] rdiagonMasks;
        return count;
    }
};

