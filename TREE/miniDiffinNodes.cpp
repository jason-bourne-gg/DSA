/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void indorderTraversal(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;

        indorderTraversal(root->left, v);
        v.push_back(root->val);
        indorderTraversal(root->right, v);

        return;
    }

    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        vector<int> v;

        if (root != NULL) {
            indorderTraversal(root, v);
        }

        for (int i = 1; i < v.size(); i++) {
            mini = min(mini, abs(v[i] - v[i - 1]));
        }
        return mini;
    }
};