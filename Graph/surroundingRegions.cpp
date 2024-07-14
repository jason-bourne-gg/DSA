class Solution
{
private:
    void dfs(int x, int y, vector<vector<char>> &board,
             vector<vector<bool>> &vis)
    {
        vis[x][y] = true;
        board[x][y] = 'Q';
        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto dir : dirs)
        {
            int newx = x + dir.first;
            int newy = y + dir.second;

            if (newx >= 0 && newx < rows && newy >= 0 && newy < cols &&
                !vis[newx][newy] && board[newx][newy] == 'O')
            {
                dfs(newx, newy, board, vis);
            }
        }

        return;
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || i == n - 1 || j == 0 ||
                     j == m - 1) &&
                    !vis[i][j] && board[i][j] == 'O')
                {
                    // cout << i << j << endl;
                    dfs(i, j, board, vis);
                }
            }
        }
        // printint Board after DFS
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // making surrounding regions as 'X'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        // reverting back edge regions to "O"
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'Q')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};