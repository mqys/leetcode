class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rules: 1x9 9x1 3x3
        // // --- 24 ms ---
        // // check 1x9 
        // for (vector<char> vc : board) {
        //     unordered_map<char, int> um;
        //     for (char c : vc) {
        //         if (c == '.')
        //             continue;
        //         ++um[c];
        //         if (um[c] > 1)
        //             return false;
        //     }
        // }
        // // check 9x1
        // for (int i = 0; i < 9; ++i) {
        //     unordered_map<char, int> um;
        //     for (int j = 0; j < 9; ++j) {
        //         if (board[j][i] == '.')
        //             continue;
        //         ++um[board[j][i]];
        //         if (um[board[j][i]] > 1) 
        //             return false;
        //     }
        // }
        // // check 3x3
        // for (int i = 0; i < 9; i += 3) {
        //     for (int j = 0; j < 9; j += 3) {
        //         unordered_map<char, int> um;
        //         for (int ii = i, jj = j; ii < i + 3; ++ii, jj = j) {
        //             for (; jj < j + 3; ++jj) {
        //                 if (board[ii][jj] == '.')
        //                     continue;
        //                 ++um[board[ii][jj]];
        //                 if (um[board[ii][jj]] > 1)
        //                     return false;
        //             }
        //         }
        //     }
        // }
        // return true;
        
        // --- 12 ms ---
        // --- use space to avoid repeating traversal ---
        // use extra space to record whether used in different rectangles
        int usedRow[9][9] = {0}, usedCol[9][9] = {0}, usedRec[3][3][9] = {0}; 
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') 
                    continue;
                int num = board[i][j] - '0' - 1; // index need to -1
                if (usedRow[i][num] || usedCol[j][num] || usedRec[i/3][j/3][num])
                    return false;
                usedRow[i][num] = usedCol[j][num] = usedRec[i/3][j/3][num] = 1;
            }
        }
        return true;
    }
};