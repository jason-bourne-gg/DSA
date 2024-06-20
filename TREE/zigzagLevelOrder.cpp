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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        int reverse = -1;
        while (!q.empty()) {
            int size = q.size();
            vector<int> tempArr;
            
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                tempArr.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            if (reverse > 0)
                std::reverse(tempArr.begin(), tempArr.end());
            ans.push_back(tempArr);
            reverse = reverse * -1;
        }
        return ans;
    }
};