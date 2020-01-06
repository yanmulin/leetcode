#include <string>
#include <assert.h>
#include <iostream>
#define ABS(x) ((x)>=0?(x):-(x))
using namespace std;
class Solution {
private:
    int nextStep(int row, int numRows, int *col) {
        int numCols = numRows - 1;
        int c = *col % numCols;
        if (c == 0 && (row == 0 || row == numRows - 1)) {
            *col += numCols;
            return 2 * numRows - 2;
        } else if (c == 0) {
            *col += numCols - row;
            return numRows - row - 1 + numCols - row;
        } else {
            *col += numCols - c;
            return numCols - c + row;
        }
    }
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= 2) return s;
        int i = 0, col = 0, size = s.size();
        string res = "";
        for (int row=0;row<numRows;row++) {
            int n = row, col = 0;
            while (n < size) {
                res.push_back(s[n]);
                n += nextStep(row, numRows, &col);
                // cout << "(r, c)=(" << row << ", " << col << "), n=" << n << endl;
            }
        }
        return res;
    }
};
