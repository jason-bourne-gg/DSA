#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
private:
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<int> &adj[])
    {
        vis[node] = true;

        for (auto adj : adj[node])
        {
            dfs(adj, vis, st, adj);
        }

        st.push(node);

        return;
    }

public:
    vector<int> getTopoSort(int N, vector<int> adj[])
    {
        vector<bool> vis(N, false);
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};