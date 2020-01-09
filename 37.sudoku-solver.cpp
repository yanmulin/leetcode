#include <vector>

using namespace std;

#define MASK_IDX(ch) ((ch)-'1')
#define AREA_N(r, c) (((r)/3)*3+(c)/3)
class Solution {
private:
    const static int SudokuSize = 9;
    bool row_mask[SudokuSize][SudokuSize] = {false};
    bool col_mask[SudokuSize][SudokuSize] = {false};
    bool area_mask[SudokuSize][SudokuSize] = {false};

    bool validate(char ch, int r, int c) {
        if (row_mask[r][MASK_IDX(ch)]) return false;
        if (col_mask[c][MASK_IDX(ch)]) return false;
        if (area_mask[AREA_N(r, c)][MASK_IDX(ch)]) return false;

        return true;
    }

    bool helper(vector<vector<char>> &board, int r, int c) {
        if (c >= SudokuSize) return helper(board, r+1, 0);
        if (r >= SudokuSize) return true;
        if (isdigit(board[r][c])) return helper(board, r, c+1);
        
        for (char d='1';d<='9';d++) {
            if (!validate(d, r, c)) continue;
            board[r][c] = d;
            
            int idx = MASK_IDX(d);
            row_mask[r][idx] = true;
            col_mask[c][idx] = true;
            area_mask[AREA_N(r,c)][idx] = true;

            if (helper(board, r, c+1)) return true;

            board[r][c] = '.';
            row_mask[r][idx] = false;
            col_mask[c][idx] = false;
            area_mask[AREA_N(r, c)][idx] = false;
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        for (int i=0;i<SudokuSize;i++) {
            for (int j=0;j<SudokuSize;j++) {
                if (!isdigit(board[i][j])) continue;
                char ch = board[i][j];
                if (!validate(ch, i, j)) return;
                int idx = MASK_IDX(ch);
                row_mask[i][idx] = col_mask[j][idx] = area_mask[AREA_N(i,j)][idx] = true;
            }
        }
        helper(board, 0, 0);
    }
};
