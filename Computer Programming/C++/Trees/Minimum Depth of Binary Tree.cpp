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
    int minDepth(TreeNode* root) 
    {
        return function(root);;    
    }

    int function(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left == NULL)
            return 1 + function(root->right);

        if(root->right == NULL)
            return 1 + function(root->left);

        // Both children exist
        return 1 + min(function(root->left), function(root->right));
    }
};
