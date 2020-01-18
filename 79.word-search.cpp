class Solution {
private:
    bool existRecurse(vector<vector<char>>& board, string &word, int idx, int row, int col) {
        if (idx >= word.size()) return true;
        if (row < 0 || row >= board.size()) return false;
        if (col < 0 || col >= board[0].size()) return false;
        if (board[row][col] != word[idx]) return false;

        board[row][col] = '\0';
        if (existRecurse(board, word, idx+1, row+1, col)) return true;
        if (existRecurse(board, word, idx+1, row-1, col)) return true;
        if (existRecurse(board, word, idx+1, row, col+1)) return true;
        if (existRecurse(board, word, idx+1, row, col-1)) return true;
        board[row][col] = word[idx];

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0) return false;
        int n = board.size(), m = board[0].size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (existRecurse(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
