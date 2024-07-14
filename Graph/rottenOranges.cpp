#include <queue>
#include <iostream>
using namespace std;

class Solution
{
private:
public:
    int timeToRotOranges(vector<vector<int>> &adj)
    {
        queue<pair<int, int>> q;
        int rows = adj.size();
        int cols = adj[0].size();
        int freshCount = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (adj[i][j] == 2)
                    q.push({i, j});
                else if (adj[i][j] == 1)
                    freshCount++;
            }
        }

        if (freshCount == 0)
            return -1;

        int minutes = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int size = q.size();
            bool freshRotten = false;

            while (size--)
            {
                int nodei = q.front().first;
                int nodej = q.front().second;
                q.pop();

                for (auto [dx, dy] : dir)
                {
                    int newnodei = nodei + dx;
                    int newnodej = nodei + dy;

                    if (newnodei < rows && newnodei >= 0 && newnodej < cols && newnodej >= 0 && adj[newnodei][newnodej] == 1)
                    {
                        adj[newnodei][newnodej] = 2;
                        q.push({newnodei, newnodej});
                        freshCount--;
                        freshRotten = true;
                    }
                }
            }

            if (freshRotten)
                minutes++;
        }
        if (freshCount != 0)
            return -1;

        return minutes;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    int result = solution.timeToRotOranges(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl;

    return 0;
}