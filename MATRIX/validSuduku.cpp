#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9)
            return false;

        // Check rows, columns, and 3x3 sub-grids
        for (int i = 0; i < 9; i++) {
            set<char> rowSet, colSet, subGridSet;
            for (int j = 0; j < 9; j++) {
                // Check rows
                if (board[i][j] != '.') {
                    if (rowSet.find(board[i][j]) != rowSet.end())
                        return false;
                    rowSet.insert(board[i][j]);
                }

                // Check columns
                if (board[j][i] != '.') {
                    if (colSet.find(board[j][i]) != colSet.end())
                        return false;
                    colSet.insert(board[j][i]);
                }

                // Check 3x3 sub-grids
                int subGridRow = 3 * (i / 3) + j / 3;
                int subGridCol = 3 * (i % 3) + j % 3;
                if (board[subGridRow][subGridCol] != '.') {
                    if (subGridSet.find(board[subGridRow][subGridCol]) !=
                        subGridSet.end())
                        return false;
                    subGridSet.insert(board[subGridRow][subGridCol]);
                }
            }
        }
        return true;
    }
};
