/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
private:
    Node *dfs(Node *node, std::unordered_map<Node *, Node *> &mp)
    {
        if (mp.find(node) != mp.end())
        {
            return mp[node];
        }

        // Create a new clone node
        Node *clone = new Node(node->val);
        mp[node] = clone;

        // Recursively clone all the neighbors
        for (auto neighbor : node->neighbors)
        {
            clone->neighbors.push_back(dfs(neighbor, mp));
        }

        return clone;
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        // Map to store the cloned nodes
        unordered_map<Node *, Node *> mp;
        return dfs(node, mp);
    }
};