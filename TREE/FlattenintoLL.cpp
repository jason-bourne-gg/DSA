/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    TreeNode *prev = nullptr;

public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        if (root->right)
            flatten(root->right);
        if (root->left)
            flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};