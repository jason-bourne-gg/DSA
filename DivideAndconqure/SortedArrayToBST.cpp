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
    // Helper function to construct the tree recursively
    TreeNode *makeTree(vector<int> &nums, int low, int hi)
    {
        if (low > hi)
            return nullptr;

        // Find the middle element to maintain the balance
        int mid = low + (hi - low) / 2;

        // Create the root node with the middle value
        TreeNode *root = new TreeNode(nums[mid]);

        // Recursively construct the left and right subtrees
        root->left = makeTree(nums, low, mid - 1); // Left subtree
        root->right = makeTree(nums, mid + 1, hi); // Right subtree

        return root;
    }

public:
    // Main function to convert sorted array to BST
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return makeTree(nums, 0, nums.size() - 1);
    }
};
