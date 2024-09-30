/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            Node *prev = nullptr;

            while (size--)
            {
                Node *temp = q.front();
                q.pop();

                temp->next = prev;
                prev = temp;

                /* WHILE CRUX OF TH EPROBLEM IS TO HAVE A PREV
                POINTER INITILIZED TO  NULL and WE START ITERATING FROM RIGHT */

                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        return root;
    }
};