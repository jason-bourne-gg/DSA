#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void modifyCell(int i, int j, vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        int countLive = 0;

        // Directions for the 8 neighboring cells
        vector<pair<int, int>> directions = {
            {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

        // Count live neighbors
        for (auto &dir : directions)
        {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2))
            {
                countLive++;
            }
        }

        // Apply the Game of Life rules
        if (board[i][j] == 1)
        {
            if (countLive < 2 || countLive > 3)
            {
                board[i][j] = 2; // Live cell that becomes dead
            }
        }
        else
        {
            if (countLive == 3)
            {
                board[i][j] = 3; // Dead cell that becomes live
            }
        }
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                modifyCell(i, j, board);
            }
        }

        // Finalize the board
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 2)
                {
                    board[i][j] = 0; // Mark dead
                }
                else if (board[i][j] == 3)
                {
                    board[i][j] = 1; // Mark live
                }
            }
        }
    }
};

void printBoard(const vector<vector<int>> &board)
{
    for (const auto &row : board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution sol;
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};

    cout << "Original Board:" << endl;
    printBoard(board);

    sol.gameOfLife(board);

    cout << "\nNext Generation Board:" << endl;
    printBoard(board);

    return 0;
}
