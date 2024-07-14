#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    bool detectbfscycle(int src, int parent, vector<bool> &vis, vector<vector<int>> &adj, queue<pair<int, int>> &q)
    {
        vis[src] = true;
        q.push({src, parent});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neighbour : adj[node])
            {
                if (!vis[neighbour])
                {
                    vis[neighbour] = 1;
                    q.push({neighbour, node});
                }
                else if (neighbour != parent)
                    return true;
            }
        }
        return false;
    }

    bool detectdfscycle(int src, int parent, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[src] = true;

        for (auto neighbour : adj[src])
        {
            if (!vis[neighbour])
            {
                vis[neighbour] = 1;
                bool isCycle = detectdfscycle(neighbour, src, vis, adj);
                if (isCycle == true)
                    return true;
            }
            else if (neighbour != parent)
                return true;
        }
        return false;
    }

public:
    bool bfsDetectCycle(int n, vector<vector<int>> &adj)
    {
        vector<bool> vis(n, false); // if graph is 0 based else size = vis[n+1] if graph is 1 based
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bool hasCycle = detectbfscycle(i, -1, vis, adj, q);
                if (hasCycle == true)
                    return true;
            }
        }
        return false;
    }

    bool dfsDetectCycle(int n, vector<vector<int>> &adj)
    {
        vector<bool> vis(n, false); // if graph is 0 based else size = vis[n+1] if graph is 1 based

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bool hasCycle = detectdfscycle(i, -1, vis, adj);
                if (hasCycle == true)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Example graph with 5 nodes (0-based index)
    int n = 5;
    vector<vector<int>> adj = {
        {1, 2},    // neighbors of node 0
        {0, 3, 4}, // neighbors of node 1
        {0, 4},    // neighbors of node 2
        {1},       // neighbors of node 3
        {1, 2}     // neighbors of node 4
    };

    bool hascycleinbfs = solution.bfsDetectCycle(n, adj);
    bool hascycleindfs = solution.dfsDetectCycle(n, adj);
    cout << "hascycleinbfs : " << hascycleinbfs << endl;
    cout << "hascycleindfs : " << hascycleindfs << endl;

    return 0;
}