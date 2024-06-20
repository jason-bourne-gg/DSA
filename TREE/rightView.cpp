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
class Solution {
public:
    // Helper function to traverse the binary tree and collect nodes for the right view
    void solve(TreeNode* root, int level, vector<int> &ans) {
        // Base case: if the current node is null, simply return
        if (root == NULL) {
            return;
        }
        
        // If this is the first node at the current level, add it to the result
        if (level == ans.size()) {  
            ans.push_back(root->val);
        }
        
        // Recurse for the right subtree first, as we want the right view
        solve(root->right, level + 1, ans);
        // Then recurse for the left subtree
        solve(root->left, level + 1, ans);
    }

    // Function to get the right view of a binary tree
    vector<int> rightSideView(TreeNode* root) {
        // Vector to store the right view nodes
        vector<int> ans;
        // Call the recursive helper function starting from the root at level 0
        solve(root, 0, ans);
        // Return the result vector containing the right view nodes
        return ans;
    }
};