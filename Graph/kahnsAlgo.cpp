#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> topoSortUsingKahnAlgo(int N, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(N, 0);
        vector<int> ans;

        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
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
    vector<int> result = sol.topoSortUsingKahnAlgo(N, adj);

    cout << "Topological Sort: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
