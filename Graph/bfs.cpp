#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
public:
    // directed Graph or undirected graph
    vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
    {
        queue<int> q;
        vector<int> ans;
        vector<bool> vis(n, false); // if grapgh is 0 based else size = vis[n+1] if graph is 1 based

        vis[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto neighbour : adj[node])
            {
                if (!vis[neighbour])
                {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return ans;
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

    vector<int> result = solution.bfsTraversal(n, adj);

    for (int node : result)
    {
        cout << node << " ";
    }

    return 0;
}