#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/* Intution behind using stack is..since the definition of
topo sort is "LINEAR ordering of the nodes in such a way
 that if there is an edge from u to v the  u should always come before v in that ordering".
 Hence, we store nodes whose DFS is completed in stack and just print them
 to get ONE of the possible solutions*/
class Solution
{
private:
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = true;

        for (auto neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                dfs(neighbor, vis, st, adj);
            }
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
            {
                dfs(i, vis, st, adj);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main()
{
    int N = 6;
    vector<int> adj[6];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution sol;
    vector<int> result = sol.getTopoSort(N, adj);

    cout << "Topological Sort: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
