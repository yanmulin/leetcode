class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int nr = board.size(), nc = board[0].size();
        set<char> digits;
        // validate rows
        for (int i=0;i<nr;i++) {
            digits.clear();
            for (int j=0;j<nc;j++) {
                if (board[i][j] == '.') continue;
                if (digits.find(board[i][j]) != digits.end()) 
                    return false;
                else digits.insert(board[i][j]);
            }
        }

        // validate cols
        for (int i=0;i<nc;i++) {
            digits.clear();
            for (int j=0;j<nr;j++) {
                if (board[j][i] == '.') continue;
                if (digits.find(board[j][i]) != digits.end()) 
                    return false;
                else digits.insert(board[j][i]);
            }
        }

        // validate 3 * 3
        for (int i=0;i<9;i++) {
            digits.clear();
            int startRow = (i / 3) * 3;
            int startCol = (i % 3) * 3;
            for (int j=0;j<9;j++) {
                char digit = board[startRow + j / 3][startCol + j % 3];
                if (digit == '.') continue;
                if (digits.find(digit) != digits.end()) 
                    return false;
                else digits.insert(digit);
            }
        }
        return true;
    }
};
