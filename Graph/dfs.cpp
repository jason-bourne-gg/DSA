#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    /* DFS for directed graph */
    bool hasCycle(int node, unordered_map<int, vector<int>> &mp, vector<int> &visited, vector<int> &ans)
    {
        if (visited[node] == 1)
            return true; // node is being visited, so we have a cycle
        if (visited[node] == 2)
            return false; // node has been fully processed and no cycle was found

        visited[node] = 1; // mark the node as being visited

        for (auto neighbor : mp[node])
        {
            if (hasCycle(neighbor, mp, visited, ans))
                return true;
        }

        visited[node] = 2; // mark the node as fully processed
        ans.push_back(node);
        return false;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ans)
    {
        vis[node] = true;
        ans.push_back(node);
        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour])
                dfs(neighbour, adj, vis, ans);
        }
    }

public:
    // directed Graph or undirected graph
    vector<int> dfsTraversal(int n, vector<vector<int>> &adj)
    {
        vector<int> ans;
        vector<bool> vis(n, false); // if grapgh is 0 based else size = vis[n+1] if graph is 1 based
        dfs(0, adj, vis, ans);
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

    vector<int> result = solution.dfsTraversal(n, adj);

    for (int node : result)
    {
        cout << node << " ";
    }

    return 0;
}
