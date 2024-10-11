
class Solution
{
private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int idx)
    {
        // Check boundaries and if the current character matches
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx])
        {
            return false;
        }

        // If all characters are matched
        if (idx == word.size() - 1)
        {
            return true;
        }

        // Temporarily mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '%';

        // Explore all 4 directions
        bool exists = dfs(board, word, i, j + 1, idx + 1) || // Right
                      dfs(board, word, i + 1, j, idx + 1) || // Down
                      dfs(board, word, i, j - 1, idx + 1) || // Left
                      dfs(board, word, i - 1, j, idx + 1);   // Up

        // Restore the cell after backtracking
        board[i][j] = temp;

        return exists;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        // Edge case: if the word is empty, return true
        if (word == "")
        {
            return true;
        }

        // Loop over every cell in the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Start DFS if the first character matches
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        // If no path exists, return false
        return false;
    }
};
