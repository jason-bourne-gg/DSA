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

    void inorder(TreeNode* root, vector <int> &nodes)
    {
        if(!root)
            return;

        inorder(root -> left, nodes);
        nodes.push_back(root -> val);    
        inorder(root -> right, nodes); 
    }

    bool isValidBST(TreeNode* root) 
    {
        if(!root)
            return true;

        vector <int> nodes;
        inorder(root, nodes); 

        set <int> s(nodes.begin(), nodes.end());

        if(s.size() != nodes.size())
            return false;

        for(int i = 0; i < nodes.size()-1; i++)
        {
            if(nodes[i] > nodes[i+1])
                return false;
        }       

        return true;
    }
};




/* using recursion */
/* 
bool isPossible(TreeNode* root, long long l, long long r){
    if(root == nullptr)  return true;
    if(root->val < r and root->val > l)
        return isPossible(root->left, l, root->val) and 
                                isPossible(root->right, root->val, r);
    else return false;
}

public:
    bool isValidBST(TreeNode* root) {
        long long int min = -1000000000000, max = 1000000000000;
        return isPossible(root, min, max);
    }
 */