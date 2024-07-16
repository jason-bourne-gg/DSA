class Solution
{
private:
    void dfs(string src, string dest,
             unordered_map<string, vector<pair<string, double>>> mp,
             unordered_map<string, bool> &vis, double temp, double &mul)
    {

        if (vis[src] == true)
            return;
        if (src == dest)
        {
            mul = temp;
            return;
        }
        vis[src] = true;
        for (auto adj : mp[src])
        {
            if (!vis[adj.first])
            {
                dfs(adj.first, dest, mp, vis, temp * adj.second, mul);
            }
        }

        return;
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> mp;

        for (int i = 0; i < equations.size(); i++)
        {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        for (int i = 0; i < queries.size(); i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];

            unordered_map<string, bool> vis;
            double mul = -1;
            double temp = 1;

            if (mp.find(src) != mp.end())
                dfs(src, dest, mp, vis, temp, mul);

            ans.push_back(mul);
        }
        return ans;
    }
};