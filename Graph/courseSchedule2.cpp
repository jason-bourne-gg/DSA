class Solution
{
private:
    bool hasCycle(int node, unordered_map<int, vector<int>> &mp,
                  vector<int> &visited, vector<int> &ans)
    {
        if (visited[node] == 1)
            return true; // node is being visited, so we have a cycle
        if (visited[node] == 2)
            return false; // node has been fully processed and no cycle was
                          // found

        visited[node] = 1; // mark the node as being visited

        for (auto neighbor : mp[node])
        {
            if (hasCycle(neighbor, mp, visited, ans))
                return true;
        }

        visited[node] = 2; // mark the node as fully processed
        ans.push_back(node);
        // now due to recursion and ans being passed by ref, the last node will
        // be  traversed 1st and put into ans. hence we have to reverse ans;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;
        unordered_map<int, vector<int>> mp;

        // Building the adjacency list
        for (auto it : prerequisites)
        {
            mp[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses, 0);
        // 0 = unvisited, 1 = visiting, 2 = visited

        // Check for cycles in each course
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (hasCycle(i, mp, visited, ans))
                    return vector<int>();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
