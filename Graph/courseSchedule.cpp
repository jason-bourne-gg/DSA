class Solution
{
private:
    bool hasCycle(int node, unordered_map<int, vector<int>> &mp, vector<int> &visited)
    {
        if (visited[node] == 1)
            return true; // node is being visited, so we have a cycle
        if (visited[node] == 2)
            return false; // node has been fully processed and no cycle was found

        visited[node] = 1; // mark the node as being visited

        for (auto neighbor : mp[node])
        {
            if (hasCycle(neighbor, mp, visited))
                return true;
        }

        visited[node] = 2; // mark the node as fully processed
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> mp;

        // Building the adjacency list
        for (auto it : prerequisites)
        {
            mp[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited

        // Check for cycles in each course
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (hasCycle(i, mp, visited))
                    return false;
            }
        }

        return true;
    }
};
