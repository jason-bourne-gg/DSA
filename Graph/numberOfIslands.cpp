class Solution
{
private:
    void dfs(int x, int y, vector<vector<char>> &grid,
             vector<vector<bool>> &vis)
    {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vis[x][y] = true;
        int rows = grid.size();
        int cols = grid[0].size();

        for (auto dir : dirs)
        {
            int dx = dir.first;
            int dy = dir.second;

            int newx = x + dx;
            int newy = y + dy;

            if (newx >= 0 && newx < rows && newy >= 0 && newy < cols &&
                !vis[newx][newy] && grid[newx][newy] == '1')
            {
                dfs(newx, newy, grid, vis);
            }
        }
        return;
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int countIsland = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid, vis);
                    countIsland++;
                }
            }
        }
        return countIsland;
    }
};