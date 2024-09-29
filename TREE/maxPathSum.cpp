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
class Solution
{
private:
    int dfs(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
            return 0;

        int maxSumLeft = max(0, dfs(root->left, maxSum)); /* why this??? ..commetns asay kadane's algo */
        int maxSumRight = max(0, dfs(root->right, maxSum));

        maxSum = max(maxSum, root->val + maxSumLeft + maxSumRight);

        return root->val + max(maxSumLeft, maxSumRight);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        dfs(root, maxSum);

        return maxSum;
    }
};