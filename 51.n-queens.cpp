
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
    void recurse(int n, vector<string> &solution, vector<vector<string>> &results) {
        if (solution.size() == n) {
            results.push_back(solution);
            return;
        }
        string s(n, '.');
        int r = solution.size();
        for (int c=0;c<n;c++) {
            if (!isValid(n, r, c)) continue;
            s[c] = 'Q';
            colMasks[c] = true;
            diagonMasks[n-r+c-1] = true;
            rdiagonMasks[r+c] = true;
            solution.push_back(s);
            recurse(n, solution, results);
            solution.pop_back();
            colMasks[c] = false;
            diagonMasks[n-r+c-1] = false;
            rdiagonMasks[r+c] = false;
            s[c] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        colMasks = new bool[n];
        diagonMasks = new bool[2*n-1];
        rdiagonMasks = new bool[2*n-1];
        memset(colMasks, 0, n * sizeof(bool));
        memset(diagonMasks, 0, (2*n-1) * sizeof(bool));
        memset(rdiagonMasks, 0, (2*n-1) * sizeof(bool));
        vector<string> solution;
        vector<vector<string>> results;
        recurse(n, solution, results);
        delete [] colMasks;
        delete [] diagonMasks;
        delete [] rdiagonMasks;
        return results;
    }
};

